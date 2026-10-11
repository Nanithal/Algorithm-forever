#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 2;

int a[N], pre[N], suf[N], pos[N];

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pos[a[i]] = i;
        pre[i] = max(pre[i - 1], a[i]);
    }
    suf[n + 1] = INF;
    for (int i = n; i >= 1; i--)
        suf[i] = min(suf[i + 1], a[i]);

    ll ans = 0;
    int p = 0;
    for (int r = 1; r <= n; r++)
    {
        while (p < n && pos[suf[p + 1]] <= r)
        {
            p++;
        }
        int maxPos = pos[pre[r]];
        ans += min(maxPos, p);
    }
    cout << ans << endl;
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