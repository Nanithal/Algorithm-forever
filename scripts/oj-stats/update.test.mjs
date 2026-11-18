import test from 'node:test';
import assert from 'node:assert/strict';
import { validateConfig, validateState, syncStats, solvedCount, renderStats, replaceStats, fetchLuoguProfileCount, fetchLuoguWithCurl, START, END } from './update.mjs';
import { createCodeforcesAdapter } from './vendor/icpc-workbench/server/src/adapters/codeforces.ts';
import { createAtcoderAdapter } from './vendor/icpc-workbench/server/src/adapters/atcoder.ts';
import { createLuoguAdapter } from './vendor/icpc-workbench/server/src/adapters/luogu.ts';
import { createNowcoderAdapter } from './vendor/icpc-workbench/server/src/adapters/nowcoder.ts';

const NOW = '2026-11-18T02:00:00.000Z';
const empty = () => ({ version: 1, platforms: {} });
const config = extra => validateConfig({ codeforces: 'example', ...extra });
const row = (id, key, verdict = 'AC', platform = 'codeforces') => ({ externalId: id, verdict, submittedAt: NOW, problem: { platform, problemKey: key } });
const adapter = fn => ({ fetchUserSubmissions: fn });
const response = data => new Response(JSON.stringify(data), { headers: { 'content-type': 'application/json' } });

test('count distinct accepted problems rather than successful submissions', async () => {
  const state = await syncStats(config(), empty(), { codeforces: adapter(async () => [row('1', '100A'), row('2', '100A'), row('3', '100B', 'WA')]) }, { now: NOW });
  assert.equal(solvedCount(state.platforms.codeforces), 1);
  assert.equal(state.platforms.codeforces.complete, true);
  assert.match(renderStats(config(), state), /\| 1 \| 已同步/);
});

test('a failed platform retains its cache and does not block other platforms', async () => {
  const conf = config({ atcoder: 'example' });
  const previous = await syncStats(config(), empty(), { codeforces: adapter(async () => [row('1', '100A')]) }, { now: NOW });
  const state = await syncStats(conf, previous, {
    codeforces: adapter(async () => { throw new Error('HTTP 503'); }),
    atcoder: adapter(async () => [row('2', 'abc100_a', 'AC', 'atcoder')]),
  }, { now: NOW });
  assert.equal(solvedCount(state.platforms.codeforces), 1);
  assert.equal(state.platforms.codeforces.status, 'error');
  assert.equal(state.platforms.atcoder.status, 'ok');
  assert.deepEqual(previous.platforms.codeforces.status, 'ok');
  assert.match(renderStats(conf, state), /保留缓存/);
});

test('missing credentials produce an unknown value rather than zero', async () => {
  const conf = config({ codeforces: '', luogu: '123' });
  const state = await syncStats(conf, empty(), {}, { env: {}, now: NOW });
  assert.match(renderStats(conf, state), /\| — \| 更新失败.*LUOGU_COOKIE/);
  assert.equal(state.platforms.luogu.lastSuccessAt, null);
});

test('Luogu public profile supports credential-free counts and real zero', async () => {
  for (const count of [0, 258]) {
    const conf = config({ codeforces: '', luogu: '2056356' });
    const state = await syncStats(conf, empty(), { luogu: { fetchProfileCount: async () => count } }, { env: {}, now: NOW });
    assert.equal(solvedCount(state.platforms.luogu), count);
    assert.equal(state.platforms.luogu.status, 'ok');
    assert.match(renderStats(conf, state), /洛谷采用公开主页/);
    assert.equal(validateState(state), state);
  }
});

test('Luogu profile count validates account identity and field type', async () => {
  const fake = data => async () => response({ data: { user: data } });
  assert.equal(await fetchLuoguProfileCount(fake({ uid: 2056356, passedProblemCount: 258 }), '2056356'), 258);
  await assert.rejects(fetchLuoguProfileCount(fake({ uid: 1, passedProblemCount: 258 }), '2056356'));
  await assert.rejects(fetchLuoguProfileCount(fake({ uid: 2056356, passedProblemCount: '258' }), '2056356'));
});

test('Luogu falls back to the official international public profile after a 403', async () => {
  const requests = [];
  const sources = [];
  const actual = async (url, init) => {
    requests.push({ url, headers: init.headers });
    if (new URL(url).hostname === 'www.luogu.com.cn') return new Response('Forbidden', { status: 403 });
    return response({ data: { user: { uid: 2056356, passedProblemCount: 258 } } });
  };
  const count = await fetchLuoguProfileCount(actual, '2056356', { onSource: source => sources.push(source) });
  assert.equal(count, 258);
  assert.equal(requests.length, 2);
  assert.deepEqual(sources, ['https://www.luogu.com']);
  assert.equal(requests[1].headers.Referer, 'https://www.luogu.com/');
  assert(requests.every(request => !String(request.headers.Cookie).includes('__client_id')));
});

test('Luogu can use public totals when the authenticated submission endpoint is blocked', async () => {
  const conf = config({ codeforces: '', luogu: '2056356' });
  const state = await syncStats(conf, empty(), { luogu: {
    fetchUserSubmissions: async () => { throw new Error('HTTP 403'); },
    fetchProfileCount: async () => 258,
  } }, { env: { LUOGU_COOKIE: '_uid=2056356; __client_id=test' }, now: NOW });
  assert.equal(state.platforms.luogu.status, 'ok');
  assert.equal(state.platforms.luogu.countSource, 'luogu-profile');
  assert.equal(solvedCount(state.platforms.luogu), 258);
  assert.equal(state.platforms.luogu.lastSuccessAt, NOW);
});

test('the standard system client uses HTTPS and never receives a login cookie', async () => {
  const result = await fetchLuoguWithCurl('2056356', {
    pause: async () => {},
    execute: async (command, args) => {
      assert.equal(command, 'curl');
      assert.equal(args[args.indexOf('--cookie') + 1], '');
      assert.equal(args[args.indexOf('--proto') + 1], '=https');
      assert.equal(args[args.indexOf('--proto-redir') + 1], '=https');
      assert(!args.includes('--insecure'));
      assert(!args.some(value => value.includes('__client_id')));
      return { stdout: JSON.stringify({ data: { user: { uid: 2056356, passedProblemCount: 258 } } }) + '\n200\nhttps://www.luogu.com.cn/user/2056356' };
    },
  });
  assert.deepEqual(result, { count: 258, origin: 'https://www.luogu.com.cn' });
});

test('the system client rejects responses for a different user', async () => {
  await assert.rejects(fetchLuoguWithCurl('2056356', { pause: async () => {}, execute: async () => ({
    stdout: JSON.stringify({ data: { user: { uid: 1, passedProblemCount: 258 } } }) + '\n200\nhttps://www.luogu.com.cn/user/2056356',
  }) }), /用户不匹配/);
});

test('the public profile resolver tries the system client only after ordinary requests fail', async () => {
  let calls = 0;
  const count = await fetchLuoguProfileCount(async () => new Response('Forbidden', { status: 403 }), '2056356', {
    publicFallback: async () => { calls++; return { count: 258, origin: 'https://www.luogu.com' }; },
  });
  assert.equal(count, 258); assert.equal(calls, 1);
});

test('Luogu preserves an old snapshot when both authenticated and public access fail', async () => {
  const conf = config({ codeforces: '', luogu: '2056356' });
  const previous = await syncStats(conf, empty(), { luogu: { fetchProfileCount: async () => 258 } }, { env: {}, now: NOW });
  const state = await syncStats(conf, previous, { luogu: {
    fetchUserSubmissions: async () => { throw new Error('HTTP 403'); },
    fetchProfileCount: async () => { throw new Error('public HTTP 403'); },
  } }, { env: { LUOGU_COOKIE: '_uid=2056356; __client_id=test' }, now: '2026-11-19T02:00:00.000Z' });
  assert.equal(solvedCount(state.platforms.luogu), 258);
  assert.equal(state.platforms.luogu.status, 'error');
  assert.equal(state.platforms.luogu.lastSuccessAt, NOW);
  assert.match(state.platforms.luogu.error, /公开主页也未成功/);
});

test('a successful authenticated Luogu sync does not request fallback profiles', async () => {
  const conf = config({ codeforces: '', luogu: '2056356' });
  const state = await syncStats(conf, empty(), { luogu: {
    fetchUserSubmissions: async () => [row('1', 'P1001', 'AC', 'luogu')],
    fetchProfileCount: async () => { throw new Error('unexpected fallback'); },
  } }, { env: { LUOGU_COOKIE: '_uid=2056356; __client_id=test' }, now: NOW });
  assert.equal(state.platforms.luogu.status, 'ok');
  assert.equal(solvedCount(state.platforms.luogu), 1);
  assert.equal(state.platforms.luogu.snapshotCount, undefined);
});

test('an account change never displays the previous account count', async () => {
  const previous = await syncStats(config(), empty(), { codeforces: adapter(async () => [row('1', '100A')]) }, { now: NOW });
  const conf = config({ codeforces: 'different' });
  const state = await syncStats(conf, previous, { codeforces: adapter(async () => { throw new Error('offline'); }) }, { now: NOW });
  assert.equal(state.platforms.codeforces.records.length, 0);
  assert.equal(state.platforms.codeforces.handle, 'different');
  assert.doesNotMatch(renderStats(conf, state), /\| 1 \|/);
});

test('truncated history resumes its page and remains a visible lower bound', async () => {
  let calls = 0;
  const conf = config({ maxBatches: 1 });
  const first = await syncStats(conf, empty(), { codeforces: adapter(async (_, opts) => {
    opts.truncated = true; opts.backfillReachedPage = 3; return [row('1', '100A')];
  }) }, { now: NOW });
  assert.match(renderStats(conf, first), /≥ 1/);
  const next = await syncStats(conf, first, { codeforces: adapter(async (_, opts) => {
    calls++; assert.equal(opts.backfill, true); assert.equal(opts.backfillFromPage, 3);
    assert(opts.knownExternalIds.has('1')); return [row('2', '100B')];
  }) }, { now: NOW });
  assert.equal(calls, 1);
  assert.equal(next.platforms.codeforces.complete, true);
  assert.equal(solvedCount(next.platforms.codeforces), 2);
});

test('failure in a later batch retains the completed earlier batch', async () => {
  let calls = 0;
  const state = await syncStats(config(), empty(), { codeforces: adapter(async (_, opts) => {
    if (++calls === 2) throw new Error('HTTP 502');
    opts.truncated = true; opts.backfillReachedPage = 2; return [row('1', '100A')];
  }) }, { now: NOW });
  assert.equal(solvedCount(state.platforms.codeforces), 1);
  assert.equal(state.platforms.codeforces.status, 'error');
  assert.equal(state.platforms.codeforces.pending, true);
});

test('incremental rejudging updates a previous submission verdict', async () => {
  const previous = await syncStats(config(), empty(), { codeforces: adapter(async () => [row('1', '100A', 'SKIPPED')]) }, { now: NOW });
  const state = await syncStats(config(), previous, { codeforces: adapter(async (_, opts) => {
    assert.equal(opts.knownVerdicts.get('1'), 'SKIPPED'); return [row('1', '100A')];
  }) }, { now: NOW });
  assert.equal(solvedCount(state.platforms.codeforces), 1);
});

test('upstream source restrictions are never shown as a complete total', async () => {
  const state = await syncStats(config(), empty(), { codeforces: adapter(async (_, opts) => {
    opts.directScanNote = '部分来源受限'; return [row('1', '100A')];
  }) }, { now: NOW });
  assert.equal(state.platforms.codeforces.status, 'partial');
  assert.match(renderStats(config(), state), /≥ 1/);
  const markdown = renderStats(config(), state);
  assert.equal(markdown.split('\n').slice(0, 6).filter(line => line.startsWith('|')).length, 6);
  assert.match(markdown, /> Codeforces：部分来源受限/);
});

test('full scan failure preserves the old completed snapshot', async () => {
  const previous = await syncStats(config(), empty(), { codeforces: adapter(async () => [row('1', '100A')]) }, { now: NOW });
  const state = await syncStats(config(), previous, { codeforces: adapter(async () => { throw new Error('timeout'); }) }, { now: NOW, full: true });
  assert.equal(solvedCount(state.platforms.codeforces), 1);
});

test('secrets are removed from stored error messages', async () => {
  const secret = '_uid=123; __client_id=secret-value';
  const conf = config({ codeforces: '', luogu: '123' });
  const state = await syncStats(conf, empty(), { luogu: adapter(async () => { throw new Error(`failure ${secret}`); }) }, { now: NOW, env: { LUOGU_COOKIE: secret } });
  assert.doesNotMatch(JSON.stringify(state), /secret-value/);
});

test('malformed submission data is rejected without replacing cache', async () => {
  const state = await syncStats(config(), empty(), { codeforces: adapter(async () => [{ externalId: '1' }]) }, { now: NOW });
  assert.equal(state.platforms.codeforces.lastSuccessAt, null);
  assert.equal(state.platforms.codeforces.status, 'error');
});

test('README replacement preserves surrounding prose and CRLF', () => {
  const before = `用户介绍\r\n${START}\r\n旧内容\r\n${END}\r\n个人笔记`;
  const after = replaceStats(before, '第一行\n第二行');
  assert.equal(after, `用户介绍\r\n${START}\r\n第一行\r\n第二行\r\n${END}\r\n个人笔记`);
  for (const text of ['no markers', `${END}${START}`, `${START}${START}${END}`]) assert.throws(() => replaceStats(text, 'new'));
});

test('invalid account configuration and corrupt state fail closed', () => {
  assert.throws(() => config({ nowcoder: 'https://nowcoder.com/profile/1' }));
  assert.throws(() => config({ batchSize: -1 }));
  assert.throws(() => validateState({ version: 2, platforms: {} }));
  assert.deepEqual(validateState(empty()), empty());
});

test('actual upstream Codeforces adapter normalizes fixture verdicts', async () => {
  const actual = createCodeforcesAdapter(async () => response({ status: 'OK', result: [
    { id: 1, creationTimeSeconds: 1700000000, verdict: 'OK', problem: { contestId: 100, index: 'A', name: 'Example' } },
  ] }));
  const rows = await actual.fetchUserSubmissions('example', { pageDelayMs: 0 });
  assert.equal(rows[0].verdict, 'AC'); assert.equal(rows[0].problem.problemKey, '100A');
});

test('AtCoder count mode skips unrelated problem metadata requests', async () => {
  const urls = [];
  const actual = createAtcoderAdapter(undefined, async url => {
    urls.push(url);
    return response([{ id: 1, epoch_second: 1700000000, result: 'AC', problem_id: 'abc100_a', contest_id: 'abc100' }]);
  });
  const rows = await actual.fetchUserSubmissions('example', { pageDelayMs: 0 });
  assert.equal(rows[0].verdict, 'AC'); assert.equal(urls.length, 1);
});

test('Luogu count mode uses Accepted status 12 and skips metadata requests', async () => {
  const urls = [];
  const actual = createLuoguAdapter(async url => {
    urls.push(url);
    return response({ code: 200, data: { records: { result: urls.length === 1 ? [{ id: 1, status: 12, submitTime: 1700000000, problem: { pid: 'P1001' } }] : [] } } });
  });
  const rows = await actual.fetchUserSubmissions('123', { cookie: '_uid=123; __client_id=test', pageDelayMs: 0 });
  assert.equal(rows[0].verdict, 'AC'); assert.equal(rows[0].problem.problemKey, 'P1001'); assert.equal(urls.length, 2);
});

test('actual Nowcoder adapter reads community submissions independently of ACM history', async () => {
  const actual = createNowcoderAdapter(async url => {
    if (url.includes('contest-joined-history')) return response({ code: 0, data: { dataList: [], pageInfo: { pageCount: 0 } } });
    if (url.includes('practice-coding')) return new Response('暂无提交记录');
    if (url.includes('submission-history')) return response({ code: 0, data: { records: [{
      problem: { questionUuid: 'a'.repeat(32), title: 'Example' }, submission: { id: 1, createdDate: 1700000000000 }, status: { desc: '答案正确' },
    }] } });
    throw new Error(`Unexpected URL: ${url}`);
  });
  const rows = await actual.fetchUserSubmissions('123', { pageDelayMs: 0 });
  assert.equal(rows.length, 1); assert.equal(rows[0].externalId, 'community:1'); assert.equal(rows[0].verdict, 'AC');
});

test('Nowcoder contest-only request exhaustion retains the continuation cursor', async () => {
  const actual = createNowcoderAdapter(async url => {
    if (url.includes('contest-joined-history')) return response({ code: 0, data: {
      dataList: Array.from({ length: 20 }, (_, i) => ({ contestId: i + 1 })), pageInfo: { pageCount: 1 },
    } });
    if (url.includes('practice-coding')) return new Response('暂无提交记录');
    if (url.includes('submission-history')) return response({ code: 0, data: { records: [] } });
    if (url.includes('status-list')) return response({ code: 0, data: { data: [], basicInfo: { pageCount: 100 } } });
    throw new Error(`Unexpected URL: ${url}`);
  });
  const opts = { pageDelayMs: 0 };
  await actual.fetchUserSubmissions('123', opts);
  assert.equal(opts.truncated, true);
  assert.equal(opts.backfillReachedPage, 3);
});
