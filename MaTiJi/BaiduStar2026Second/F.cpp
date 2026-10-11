#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 2e5 + 1;
ll a[N];
const int INF = 0x3f3f3f3f;
const ll INFF = 0x3f3f3f3f3f3f3f3f;
void solve()
{
    ll ans = -INFF;
    int n;
    cin >> n;
    a[0] = -INFF;
    a[n + 1] = -INF;
    vector<ll> pre(n + 1);
    vector<ll> suf(n + 2);
    vector<ll> sum(n + 1);
    pre[0] = -INFF;
    sum[0] = 0;
    suf[n + 1] = -INFF;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pre[i] = max(pre[i - 1], a[i]);
        sum[i] = sum[i - 1] + a[i];
    }
    for (int i = n; i >= 1; i--)
    {
        suf[i] = max(suf[i + 1], a[i]);
    }
    for (int i = 1; i <= n - 3; i++)
    {
        ans = max(sum[i + 3] - sum[i - 1] + max(pre[i - 1], suf[i + 4]), ans);
    }
    for (int i = 2; i < n; i++)
    {
        if (i + 3 <= n)
            ans = max(sum[i + 3] - sum[i - 2] - a[i] + max(a[i - 2], a[i + 4]), ans);
        if (i - 2 >= 1 && i + 2 <= n)
            ans = max(sum[i + 2] - sum[i - 3] - a[i] + max(a[i - 3], a[i + 3]), ans);
        if (i - 3 >= 1 && i + 1 <= n)
            ans = max(sum[i + 1] - sum[i - 4] - a[i] + max(a[i - 4], a[i + 2]), ans);
    }
    cout << ans << endl;
}
int main()
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