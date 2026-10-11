#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

// 因为 n <= 5000，bitset 开到 5005 即可
const int MAXN = 5005;

void solve()
{
    int n, m;
    if (!(cin >> n >> m))
        return;

    // dp[j] 表示能否到达模 n 意义下的位置 j
    bitset<MAXN> dp;
    dp[0] = 1; // 初始在起点（相对位置 0）

    // 构造一个只包含低 n 位的掩码 (Mask)，防止移位超过 n 的位干扰
    bitset<MAXN> mask;
    for (int i = 0; i < n; i++)
    {
        mask[i] = 1;
    }

    for (int i = 0; i < m; i++)
    {
        long long a;
        cin >> a;
        int x = a % n; // 只需要关心模 n 的余数
        if (x == 0)
            continue; // 相当于绕了整圈回到原点，DP 状态不变

        // 1. 顺时针移动 x（循环左移 x 位）
        bitset<MAXN> shift_left = ((dp << x) & mask) | (dp >> (n - x));

        // 2. 逆时针移动 x（循环右移 x 位）
        bitset<MAXN> shift_right = (dp >> x) | ((dp << (n - x)) & mask);

        // 合并两种选择的状态
        dp = shift_left | shift_right;
    }

    // 检查最终是否能回到起点 0
    if (dp[0])
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}