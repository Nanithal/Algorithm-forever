// https://www.nowcoder.com/practice/15fc1513621145d9bb53260e8c0c24c2?channelPut=tracker2
// 不会的dp

#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //  dp[i][j]表示从左上角(0,0)到(i,j)最少需要多少次移动
    int n, m;
    cin >> n >> m;

    vector<string> mp(n);

    for (auto &s : mp)
        cin >> s;

    vector<int> row(n, INF); // 表示当前第 i 行中，从最近的障碍物开始，到当前列之前，所有已经可达格子里的最小 dp。

    vector<int> col(m, INF); // 表示当前第 j 列中，从最近障碍物开始，到当前行之前，能够到达的位置的最小 dp。

    // 对角线 i-j 的范围是 -(m-1) ~ (n-1)
    // 加上 m 之后变成非负数
    vector<int> diag(n + m, INF); // 表示同一条左上 → 右下对角线上，之前可以到达的位置的最小 dp。(每一条向右下的对角线它的i-j的值是固定好的)

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mp[i][j] == '*')
            {
                // 障碍物会把这一行、这一列、这一条对角线全部截断
                row[i] = INF;
                col[j] = INF;
                diag[i - j + m] = INF;

                continue;
            }

            // 起点
            if (i == 0 && j == 0)
            {
                row[i] = 0;
                col[j] = 0;
                diag[i - j + m] = 0;
                continue;
            }

            // 当前点可以从：
            // 1. 左边跳过来
            // 2. 上面跳下来
            // 3. 左上方斜着跳过来
            int dp = min({row[i], col[j], diag[i - j + m]});

            // 如果三个方向都不能到达
            if (dp == INF)
                continue;

            // 走一步到达当前格
            dp++;

            // 当前格成为后面的“可跳到的位置”
            row[i] = min(row[i], dp);
            col[j] = min(col[j], dp);
            diag[i - j + m] = min(diag[i - j + m], dp);

            // 如果已经到达终点，可以直接输出
            if (i == n - 1 && j == m - 1)
            {
                cout << dp << '\n';
                return 0;
            }
        }
    }

    cout << -1 << '\n';

    return 0;
}