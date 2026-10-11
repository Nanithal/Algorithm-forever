// 区间dp
// 令dp[l][r]意为端点在l和r之间的不相交弦所能组成的最大权值
// 对于右端点在r的弦来说可以不取：dp[l][r] = dp[l][r - 1]；
// 也可以取(要满足该弦的左端点k >= l),取完之后剩下空间也可以继续取弦即[l][k - 1]和[k + 1][r - 1]。那么dp[l][r] = w[r] + dp[l][k -1] + dp[k + 1][r - 1]
// 则两种情况取最大值即可
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int INF = 0x3f3f3f3f;
const int N = 3001;
ll dp[N][N];
int L[N]; // 以i为右端点对应的线段的左端点
ll W[N];  // 以i为右端点对应的线段的权值

void solve()
{
    int n;
    ll ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int l, r;
        ll w;
        cin >> l >> r >> w;
        L[r] = l;
        W[r] = w;
    }
    int m = 2 * n;
    for (int len = 1; len <= m; len++)
    {
        for (int l = 1; l + len - 1 <= m; l++)
        {
            int r = l + len - 1;
            dp[l][r] = dp[l][r - 1];
            int k = L[r];
            if (k >= l)
            {
                dp[l][r] = max(dp[l][r], dp[l][k - 1] + W[r] + dp[k + 1][r - 1]);
            }
        }
    }
    cout << dp[1][m] << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}