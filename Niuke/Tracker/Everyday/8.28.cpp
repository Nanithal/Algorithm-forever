#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define int ll
const int INF = 0x3f3f3f3f;

void solve()
{
    int n, k, maxn1 = 0, maxn2 = 0, minn = INF, ans = 0;
    cin >> n >> k;
    vector<int> c(n + 1);
    vector<int> pre(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
        if (c[i] > maxn1)
        {
            maxn2 = maxn1;
            maxn1 = c[i];
        }
        else if (c[i] > maxn2)
            maxn2 = c[i];
    }
    if (n == 1)
    {
        cout << c[1] << endl;
        return;
    }
    if (k + 2 >= n)
    {
        cout << maxn1 + maxn2 << endl;
        return;
    }
    ans = c[1] + c[n];
    for (int i = 0; i <= k; i++)
        pre[i] = max(c[n - i], pre[i - 1]);
    for (int i = 0; i <= k; i++)
    {
        ans = max(ans, c[i + 1] + pre[k - i]);
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}