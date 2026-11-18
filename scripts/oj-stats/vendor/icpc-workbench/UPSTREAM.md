# Upstream source

Repository: https://github.com/ZF3373/icpc-workbench
Commit: 1599d5976ea0268d816db59f815e29d429a6142d
Source tree: https://github.com/ZF3373/icpc-workbench/tree/1599d5976ea0268d816db59f815e29d429a6142d
Retrieved: 2026-11-18
License: GPL-3.0-only; the complete upstream LICENSE is included here.

This directory contains the four platform adapters and their source dependencies. The original directory layout and file contents are retained except for these changes made on 2026-11-18:

1. server/src/adapters/types.ts: expand the SyncError constructor parameter property into an equivalent declared property and assignment, so Node.js 24 can strip TypeScript without experimental transformation flags.
2. server/src/adapters/atcoder.ts: skip ensureMaps() during submission synchronization; README counts need no problem-title or difficulty resources.
3. server/src/adapters/luogu.ts: use an empty per-problem metadata fetch list; submission IDs, verdicts and problem keys remain unchanged.
4. server/src/adapters/nowcoder.ts: preserve truncation and the resume page when the separate contest request budget is exhausted, including cases where the overall request budget remains available. This prevents an incomplete contest history from being reported as complete.

A package.json was added to declare ESM. No database, desktop shell, AI features or HTTP server is started. ../.. contains the GPL-3.0-only README integration written on 2026-11-18.

