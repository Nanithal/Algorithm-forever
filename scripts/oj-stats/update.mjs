// SPDX-License-Identifier: GPL-3.0-only
// Algorithm-forever README integration, 2026-11-18.
import fs from 'node:fs/promises';
import path from 'node:path';
import { fileURLToPath } from 'node:url';
import { createCodeforcesAdapter } from './vendor/icpc-workbench/server/src/adapters/codeforces.ts';
import { createAtcoderAdapter } from './vendor/icpc-workbench/server/src/adapters/atcoder.ts';
import { createNowcoderAdapter } from './vendor/icpc-workbench/server/src/adapters/nowcoder.ts';
import { createLuoguAdapter, fetchWithChallenge } from './vendor/icpc-workbench/server/src/adapters/luogu.ts';
import { createHttpClient, PROD_RETRY } from './vendor/icpc-workbench/server/src/adapters/http.ts';
import { throttledFetch } from './vendor/icpc-workbench/server/src/net/hostThrottle.ts';

export const START = '<!-- OJ-STATS:START -->';
export const END = '<!-- OJ-STATS:END -->';
export const PLATFORMS = ['codeforces', 'nowcoder', 'luogu', 'atcoder'];
const LABELS = { codeforces: 'Codeforces', nowcoder: '牛客', luogu: '洛谷', atcoder: 'AtCoder' };
const DIR = path.dirname(fileURLToPath(import.meta.url));
const ROOT = path.resolve(DIR, '../..');

export function validateConfig(raw) {
  if (!raw || typeof raw !== 'object' || Array.isArray(raw)) throw new Error('账号配置必须是 JSON 对象');
  const config = {};
  for (const key of PLATFORMS) {
    const value = raw[key] ?? '';
    if (typeof value !== 'string') throw new Error(`${key} 账号必须是字符串`);
    const handle = value.trim();
    const valid = key === 'nowcoder' || key === 'luogu'
      ? /^[1-9]\d*$/.test(handle)
      : key === 'atcoder' ? /^[A-Za-z0-9_]{1,64}$/.test(handle) : /^[A-Za-z0-9_.-]{1,64}$/.test(handle);
    if (handle && !valid) throw new Error(`${key} 账号格式不正确：牛客／洛谷填数字 UID，CF／AtCoder 填用户名`);
    config[key] = handle;
  }
  for (const [key, fallback, min, max] of [['batchSize', 1000, 100, 5000], ['maxBatches', 2, 1, 5]]) {
    const value = raw[key] ?? fallback;
    if (!Number.isInteger(value) || value < min || value > max) throw new Error(`${key} 必须是 ${min}–${max} 的整数`);
    config[key] = value;
  }
  return config;
}

export function validateState(raw) {
  if (!raw || raw.version !== 1 || !raw.platforms || typeof raw.platforms !== 'object' || Array.isArray(raw.platforms)) {
    throw new Error('统计缓存格式不正确，请从 Git 恢复 stats/oj-stats.json');
  }
  for (const [key, item] of Object.entries(raw.platforms)) {
    if (!PLATFORMS.includes(key)) throw new Error('统计缓存含未知平台');
    if (!item || typeof item.handle !== 'string' || !Array.isArray(item.records)
        || typeof item.complete !== 'boolean' || typeof item.pending !== 'boolean'
        || !Number.isInteger(item.page) || item.page < 1) throw new Error(`${key} 缓存格式不正确`);
    for (const row of item.records) {
      if (!Array.isArray(row) || row.length !== 4 || !row.every(x => typeof x === 'string')
          || !row[0] || !row[1] || !Number.isFinite(Date.parse(row[3]))) throw new Error(`${key} 缓存记录损坏`);
    }
    for (const field of ['cursor', 'lastSuccessAt']) {
      if (item[field] && !Number.isFinite(Date.parse(item[field]))) throw new Error(`${key} 缓存时间格式不正确`);
    }
    if (item.snapshotCount !== undefined && (!Number.isSafeInteger(item.snapshotCount) || item.snapshotCount < 0 || key !== 'luogu')) {
      throw new Error(`${key} 主页统计缓存格式不正确`);
    }
  }
  return raw;
}

function emptyAccount(handle) {
  return { handle, records: [], complete: false, pending: true, page: 1, cursor: null, lastSuccessAt: null, status: 'pending', notes: [] };
}

function validateRows(rows, platform) {
  if (!Array.isArray(rows)) throw new Error('上游未返回提交列表');
  return rows.map(row => {
    if (!row || typeof row.externalId !== 'string' || !row.externalId
        || row.problem?.platform !== platform || typeof row.problem.problemKey !== 'string' || !row.problem.problemKey
        || typeof row.verdict !== 'string' || !Number.isFinite(Date.parse(row.submittedAt))) {
      throw new Error('上游返回了不完整的提交记录，本批数据未保存');
    }
    return [row.externalId, row.problem.problemKey, row.verdict, row.submittedAt];
  });
}

function latest(a, b) {
  if (!a) return b ?? null;
  if (!b) return a;
  return Date.parse(a) >= Date.parse(b) ? a : b;
}

function safeError(error, env) {
  let message = error instanceof Error ? error.message : String(error);
  for (const value of [env.LUOGU_COOKIE, env.ATCODER_COOKIE]) {
    if (value) message = message.split(value).join('[已隐藏凭据]');
  }
  // Persist a short diagnosis only; never store response bodies or request headers.
  return message.replace(/(?:__client_id|_uid|REVEL_SESSION|cookie|authorization)\s*[:=]\s*[^;\s]+/gi, '[已隐藏凭据]')
    .replace(/[\r\n]+/g, ' ').slice(0, 250);
}

export function createAdapters() {
  const http = createHttpClient(throttledFetch, PROD_RETRY);
  return {
    codeforces: createCodeforcesAdapter(http),
    nowcoder: createNowcoderAdapter(http),
    luogu: Object.assign(createLuoguAdapter(http), { fetchProfileCount: handle => fetchLuoguProfileCount(http, handle) }),
    atcoder: createAtcoderAdapter(undefined, http),
  };
}

export async function fetchLuoguProfileCount(http, handle) {
  const response = await fetchWithChallenge(http, `https://www.luogu.com.cn/user/${encodeURIComponent(handle)}`, '', undefined, {
    'x-lentille-request': 'content-only', Accept: 'application/json',
  });
  if (!response.ok) throw new Error(`洛谷公开主页 HTTP ${response.status}；可配置 LUOGU_COOKIE 使用提交记录通道`);
  let data;
  try { data = await response.json(); }
  catch { throw new Error('洛谷公开主页未返回有效 JSON；可配置 LUOGU_COOKIE 使用提交记录通道'); }
  const user = data.data?.user ?? data.currentData?.user;
  if (String(user?.uid) !== handle || !Number.isSafeInteger(user?.passedProblemCount) || user.passedProblemCount < 0) {
    throw new Error('洛谷公开主页用户不匹配或通过题数不可见；可配置 LUOGU_COOKIE 使用提交记录通道');
  }
  return user.passedProblemCount;
}

export async function syncStats(config, previous, adapters, { env = process.env, now = new Date().toISOString(), full = false, log = () => {} } = {}) {
  const state = structuredClone(previous);
  for (const key of PLATFORMS) {
    const handle = config[key];
    if (!handle) { delete state.platforms[key]; continue; }
    const old = previous.platforms[key]?.handle === handle ? structuredClone(previous.platforms[key]) : emptyAccount(handle);
    let account = full ? emptyAccount(handle) : structuredClone(old);
    let succeeded = false;
    try {
      if (key === 'luogu' && !env.LUOGU_COOKIE) {
        if (!adapters.luogu?.fetchProfileCount) throw new Error('需配置 LUOGU_COOKIE 或启用公开主页统计通道');
        log('洛谷：正在获取公开主页通过题数');
        const count = await adapters.luogu.fetchProfileCount(handle);
        if (!Number.isSafeInteger(count) || count < 0) throw new Error('洛谷主页通过题数格式不正确');
        state.platforms[key] = { ...emptyAccount(handle), snapshotCount: count, countSource: 'luogu-profile', complete: true, pending: false, status: 'ok', lastSuccessAt: now };
        continue;
      }
      delete account.snapshotCount;
      delete account.countSource;
      const records = new Map(account.records.map(row => [row[0], row]));
      for (let batch = 0; batch < config.maxBatches; batch++) {
        const opts = {
          maxSubmissions: config.batchSize,
          knownExternalIds: new Set(records.keys()),
          knownVerdicts: new Map([...records].map(([id, row]) => [id, row[2]])),
          knownProblemKeys: new Map([...records].map(([id, row]) => [id, row[1]])),
          backfill: account.pending,
          backfillFromPage: account.pending ? account.page : 1,
        };
        if (key === 'atcoder' && account.cursor) {
          const lookback = account.pending ? 0 : 12 * 3600 * 1000;
          opts.since = new Date(Math.max(0, Date.parse(account.cursor) - lookback)).toISOString();
        }
        if (key === 'luogu') opts.cookie = env.LUOGU_COOKIE;
        if (key === 'atcoder' && env.ATCODER_COOKIE) opts.cookie = env.ATCODER_COOKIE;
        log(`${LABELS[key]}：正在同步第 ${batch + 1} 批`);
        const rows = validateRows(await adapters[key].fetchUserSubmissions(handle, opts), key);
        const before = `${records.size}:${account.cursor}:${account.page}`;
        for (const row of rows) records.set(row[0], row);
        account.records = [...records.values()].sort((a, b) => a[3].localeCompare(b[3]) || a[0].localeCompare(b[0]));
        account.cursor = rows.reduce((at, row) => latest(at, row[3]), account.cursor);
        if (opts.scannedUntil) account.cursor = latest(account.cursor, opts.scannedUntil);
        account.pending = opts.truncated === true;
        account.page = account.pending ? (opts.backfillReachedPage ?? account.page) : 1;
        account.complete = !account.pending;
        account.lastSuccessAt = now;
        account.notes = opts.directScanNote ? [safeError(opts.directScanNote, env)] : [];
        account.status = account.pending || account.notes.length ? 'partial' : 'ok';
        delete account.error;
        succeeded = true;
        // Snapshots contain only normalized public submission data, never cookies.
        state.platforms[key] = structuredClone(account);
        if (!account.pending) break;
        if (`${records.size}:${account.cursor}:${account.page}` === before) {
          account.notes.push('本轮续拉游标未前进，下次重试；当前数字为已获取下限');
          state.platforms[key] = structuredClone(account);
          break;
        }
      }
    } catch (error) {
      // A failed batch must not replace a previous successful batch or another account's data.
      account = succeeded ? state.platforms[key] : old;
      state.platforms[key] = { ...account, status: 'error', error: safeError(error, env) };
      log(`${LABELS[key]}：${state.platforms[key].error}`);
    }
  }
  return state;
}

export function solvedCount(account) {
  if (account.snapshotCount !== undefined) return account.snapshotCount;
  return new Set(account.records.filter(row => row[2] === 'AC').map(row => row[1])).size;
}

function escapeMarkdown(value) {
  return String(value).replace(/[|\r\n<>]/g, ' ').replace(/\[/g, '（').replace(/\]/g, '）');
}

function timeText(iso) {
  if (!iso) return '—';
  return new Intl.DateTimeFormat('sv-SE', {
    timeZone: 'Asia/Shanghai', year: 'numeric', month: '2-digit', day: '2-digit', hour: '2-digit', minute: '2-digit', hour12: false,
  }).format(new Date(iso));
}

export function renderStats(config, state) {
  const lines = ['| 平台 | 账号 | 已通过题数 | 同步状态 | 最近成功同步（北京时间） |', '| :-- | :-- | --: | :-- | :-- |'];
  const remarks = [];
  let total = 0, available = 0, partial = false;
  for (const key of PLATFORMS) {
    const handle = config[key];
    const item = state.platforms[key]?.handle === handle ? state.platforms[key] : null;
    const known = item?.lastSuccessAt != null;
    const count = known ? solvedCount(item) : null;
    if (known) { total += count; available++; }
    const lowerBound = known && (!item.complete || item.notes?.length > 0);
    if (!known || lowerBound || item.status !== 'ok') partial = true;
    const urls = {
      codeforces: `https://codeforces.com/profile/${encodeURIComponent(handle)}`,
      nowcoder: `https://ac.nowcoder.com/acm/contest/profile/${encodeURIComponent(handle)}`,
      luogu: `https://www.luogu.com.cn/user/${encodeURIComponent(handle)}`,
      atcoder: `https://atcoder.jp/users/${encodeURIComponent(handle)}`,
    };
    const name = handle ? `[${escapeMarkdown(handle)}](${urls[key]})` : '—';
    let status = !handle ? '未配置' : !item || item.status === 'pending' ? '等待首次同步'
      : item.status === 'error' ? `更新失败${known ? '，保留缓存' : ''}：${escapeMarkdown(item.error)}`
      : item.pending ? '历史记录同步中，下次继续' : item.notes?.length ? '部分来源受限' : '已同步';
    lines.push(`| ${LABELS[key]} | ${name} | ${count === null ? '—' : `${lowerBound ? '≥ ' : ''}${count}`} | ${status} | ${timeText(item?.lastSuccessAt)} |`);
    for (const note of item?.notes ?? []) remarks.push(`${LABELS[key]}：${escapeMarkdown(note)}`);
  }
  lines.push('', `已获取合计：**${available ? `${partial ? '≥ ' : ''}${total}` : '—'}**。同一平台按题目去重，跨平台分别计数。`, '',
    '数据由 [icpc-workbench](https://github.com/ZF3373/icpc-workbench) 平台适配器获取；AtCoder 使用社区镜像，可能有收录延迟。',
    '“≥”表示历史记录尚未拉完、来源受限或部分平台未取得数据；失败时显示上次成功缓存。');
  if (remarks.length) lines.push('', ...remarks.map(note => `> ${note}`));
  if (state.platforms.luogu?.countSource === 'luogu-profile') lines.push('', '洛谷采用公开主页显示的通过题数；其他平台按可获取的提交记录统计。');
  return lines.join('\n');
}

export function replaceStats(readme, body) {
  if (readme.split(START).length !== 2 || readme.split(END).length !== 2 || readme.indexOf(START) > readme.indexOf(END)) {
    throw new Error('README 必须包含且仅包含一组有效的 OJ-STATS:START / OJ-STATS:END 标记；未修改任何文件');
  }
  const newline = readme.includes('\r\n') ? '\r\n' : '\n';
  return readme.slice(0, readme.indexOf(START) + START.length) + newline
    + body.replace(/\r?\n/g, newline) + newline + readme.slice(readme.indexOf(END));
}

async function readState(filename) {
  try { return validateState(JSON.parse(await fs.readFile(filename, 'utf8'))); }
  catch (error) { if (error.code === 'ENOENT') return { version: 1, platforms: {} }; throw error; }
}

async function writeIfChanged(filename, content) {
  try { if (await fs.readFile(filename, 'utf8') === content) return; }
  catch (error) { if (error.code !== 'ENOENT') throw error; }
  await fs.mkdir(path.dirname(filename), { recursive: true });
  const temporary = `${filename}.${process.pid}.tmp`;
  try { await fs.writeFile(temporary, content, 'utf8'); await fs.rename(temporary, filename); }
  finally { await fs.rm(temporary, { force: true }); }
}

export async function main(argv = process.argv.slice(2)) {
  const options = { config: path.join(DIR, 'config.json'), state: path.join(ROOT, 'stats/oj-stats.json'), readme: path.join(ROOT, 'README.md') };
  for (let i = 0; i < argv.length; i++) {
    const name = argv[i].replace(/^--/, '');
    if (['dry-run', 'offline', 'full'].includes(name)) options[name] = true;
    else if (['config', 'state', 'readme'].includes(name) && argv[i + 1] && !argv[i + 1].startsWith('--')) options[name] = path.resolve(argv[++i]);
    else if (name === 'help') { console.log('node scripts/oj-stats/update.mjs [--dry-run] [--offline] [--full] [--config FILE] [--state FILE] [--readme FILE]'); return; }
    else throw new Error(`未知或缺少参数：${argv[i]}`);
  }
  const config = validateConfig(JSON.parse(await fs.readFile(options.config, 'utf8')));
  const readme = await fs.readFile(options.readme, 'utf8');
  replaceStats(readme, ''); // Validate markers before making requests or writing state.
  const previous = await readState(options.state);
  const state = options.offline ? previous : await syncStats(config, previous, createAdapters(), { full: options.full, log: console.log });
  const body = renderStats(config, state);
  if (options['dry-run']) { console.log(body); return; }
  await writeIfChanged(options.state, JSON.stringify(state, null, 2) + '\n');
  await writeIfChanged(options.readme, replaceStats(readme, body));
  console.log('README 统计区域已更新');
  const failed = PLATFORMS.filter(key => config[key] && state.platforms[key]?.status === 'error');
  if (failed.length) {
    console.error(`同步失败（已保留缓存）：${failed.join(', ')}`);
    process.exitCode = 1;
  }
}

if (process.argv[1] && path.resolve(process.argv[1]) === fileURLToPath(import.meta.url)) {
  main().catch(error => { console.error(error.message); process.exitCode = 1; });
}
