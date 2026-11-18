# README 刷题统计

使用 ZF3373/icpc-workbench 的 Codeforces、牛客、洛谷、AtCoder 适配器，更新仓库 README 中的统计表。无需运行工作台服务、数据库或安装 npm 依赖；本地运行需要 Node.js 24 或更高版本。

## 首次配置

编辑同目录 `config.json`，将四个平台账号填入字符串：

```json
{
  "codeforces": "你的CF用户名",
  "nowcoder": "你的牛客数字UID",
  "luogu": "你的洛谷数字UID",
  "atcoder": "你的AtCoder用户名",
  "batchSize": 1000,
  "maxBatches": 2
}
```

牛客 UID 取自 `https://ac.nowcoder.com/acm/contest/profile/数字UID`；洛谷 UID 取自 `https://www.luogu.com.cn/user/数字UID`。暂时不用的平台留空字符串，README 显示“未配置”，不会计为 0。

洛谷默认通过上游的 HTTP／挑战处理模块读取公开个人主页的 `passedProblemCount`，无需 Cookie。若主页统计不可见，或希望改用提交记录通道，可以在 GitHub 仓库 **Settings → Secrets and variables → Actions → New repository secret** 添加可选 `LUOGU_COOKIE`。值为本人登录洛谷后的 Cookie，至少包含 `_uid` 和 `__client_id`；登录过期后更新同一个 Secret。Cookie 只放 Secret 或本地进程环境变量。

AtCoder 默认用 kenkoooo 社区镜像，无需 Cookie。可选 Secret `ATCODER_COOKIE` 用于适配器的本人比赛提交补充扫描；不配置也能使用主通道。

配置、脚本、第三方适配器、缓存和完整执行工作流保存在 `automation` 分支；`main` 仅保留算法源码、展示用 README 和很小的定时入口。将两个分支推送到 GitHub 后，打开 **Actions → Update OJ statistics → Run workflow**。默认每天北京时间 08:17 左右运行，实际时间受 GitHub 调度影响。GitHub 定时入口必须存在于默认分支，因此 main 中的这个入口文件需要保留。

入口通过 `workflow_call` 调用 automation 分支：分别检出两个分支，从 automation 读取配置和缓存，向 main 的 README 写入统计，再把缓存提交回 automation。使用内置 `GITHUB_TOKEN`，无需额外 PAT；如分支保护禁止机器人直接推送，需要按仓库规则允许工作流写入。

## 本地运行

切换到 automation 分支后，在仓库根目录执行。`--readme` 指向另一个 main 工作目录中的 README：

```powershell
node --test scripts/oj-stats/update.test.mjs
node scripts/oj-stats/update.mjs --dry-run --readme C:/path/to/main-worktree/README.md
node scripts/oj-stats/update.mjs --readme C:/path/to/main-worktree/README.md
```

`--dry-run` 仍会联网获取数据，但只输出预览、不写文件。`--offline --dry-run` 只预览已有缓存。若使用洛谷的可选提交记录通道，在当前 PowerShell 进程中设置 `$env:LUOGU_COOKIE`。

脚本只替换 `<!-- OJ-STATS:START -->` 与 `<!-- OJ-STATS:END -->` 之间的内容。标记缺失、重复、顺序错误或缓存损坏时停止，不覆盖其他 README 内容。

## 分批同步与计数口径

- 按平台内题目键去重 AC，统计的是平台记录；跨平台不去重。
- `stats/oj-stats.json` 保存提交 ID、题目键、判定、时间和续拉游标，提交到 automation 分支；展示用 README 提交到 main。缓存不保存 Cookie。不要手工编辑缓存内部结构。
- 首次同步每个平台每批最多读取约 1000 条新记录，每轮最多 2 批，沿用上游请求限速与重试。历史较多时显示 `≥ N` 与“历史记录同步中”，下次运行从缓存继续。可以连续手动运行，也可以等待每日任务。
- 一个平台失败时其余平台继续；失败平台保留上次成功数据与时间，工作流先提交可用结果，再标记失败，方便在 Actions 查看错误。
- AtCoder 镜像可能延迟收录。牛客适配器有最近 20 场比赛及单轮请求预算限制，部分更早比赛可能无法覆盖；出现上游限制时表格显示下限，不能视为牛客主页的完整总数。ACM 练习和在线编程分别读取后合并。
- 洛谷默认采用公开主页的通过题数；设置 Cookie 时切换为提交接口记录去重，可能包含 P/B/U/T/SP 等题目。两种通道与其他平台主页采用的展示口径不保证相同，README 会注明使用公开主页计数。
- 增量同步沿用上游已知提交早停规则。历史重判、删题或需要重新核对总数时，可以执行一次 `node scripts/oj-stats/update.mjs --full`，或在手动工作流勾选 `full`。若本次未拉完，后续运行取消 `full`，继续补全；持续勾选会反复从头扫描。
- 合计是四个平台已获取数据的和；存在未配置、未成功同步、历史截断或来源限制时，用 `≥` 标注。

## 来源与更新

平台实现固定到 icpc-workbench 的一个提交，详见 `vendor/icpc-workbench/UPSTREAM.md`。这部分统计工具与附带的上游代码按 GPL-3.0-only 提供，完整许可证位于 `vendor/icpc-workbench/LICENSE`。

升级上游时从新提交替换相应源文件，核对 UPSTREAM.md 中记录的兼容、计数模式和续拉修正，再运行测试与个人账号的真实同步。不要在每日工作流中自动下载上游最新代码，以免接口或统计口径突然改变。
