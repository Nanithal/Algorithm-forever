
// 二分答案

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
ll check(ll x, ll n, ll m)
{
    ll cnt = 0;
    for (ll i = 1; i <= n; i++)
    {
        ll val = i * i - x;
        if (val > 0)
            cnt += min(m, (ll)sqrt(val));
    }
    return cnt;
}
void solve()
{
    ll ans = 0, l, r;
    ll n, m, k;
    cin >> n >> m >> k;
    l = 1ll - 1ll * m * m;
    r = 1ll * n * n - 1ll;
    while (l < r)
    {
        ll mid = l + ((r - l + 1) >> 1); // 这里要向上取整
        if (check(mid, n, m) >= k)
            l = mid;
        else
            r = mid - 1;
    }
    ll num = 0;
    for (ll i = 1; i <= n; i++)
    {
        ll val = i * i - l - 1;
        if (val > 0)
        {
            ll up = min(m, (ll)sqrt(val));
            num += up;
            ans += up * i * i;
            ans -= (up * (up + 1) * (2 * up + 1)) / 6;
        }
    }
    ans += (k - num) * l;
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