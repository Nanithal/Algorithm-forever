# Algorithm Forever · Automation

本分支保存刷题统计工具、配置、缓存和第三方平台适配器。算法源码和展示用 README 位于 [main 分支](https://github.com/Nanithal/Algorithm-forever/tree/main)。

## 自动更新

main 分支的极小工作流每天北京时间 08:17 调用本分支的工作流。运行时分别检出两个分支，缓存提交到 automation，只将统计表写回 main 的 README。

手动运行入口：[Update OJ statistics](https://github.com/Nanithal/Algorithm-forever/actions/workflows/update-oj-stats.yml)。两个分支推送到 GitHub 后生效。

## 文件

- `scripts/oj-stats/update.mjs`：数据获取与 README 更新。
- `scripts/oj-stats/config.json`：平台账号。
- `scripts/oj-stats/update.test.mjs`：统计工具测试。
- `stats/oj-stats.json`：提交记录、统计缓存和续拉进度。
- `scripts/oj-stats/vendor/icpc-workbench/`：固定版本的上游平台适配器、依赖与许可证。

详细说明见 [统计工具说明](scripts/oj-stats/README.md)。

## 本地验证

需要 Node.js 24。在本分支运行：

```powershell
node --test scripts/oj-stats/update.test.mjs
node scripts/oj-stats/update.mjs --offline --dry-run --readme C:/path/to/main-worktree/README.md
```

为避免覆盖本分支的工具说明，本地更新时用 `--readme` 显式指定 main 工作目录的 README。

