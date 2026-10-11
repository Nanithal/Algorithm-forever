#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, l, r;
inline ll getrow(ll x)
{
    return (sqrt(8.0 * x + 1) - 1.0) / 2.0 + 1e-9 + 0.999999999;
}
void solve()
{
    bool ok = 1;
    cin >> n >> l >> r;
    ll mid = l + ((r - l) >> 1);
    ll row1 = getrow(l);
    ll cow1 = -row1 * (row1 - 1) / 2 + l;
    ll row2 = getrow(r);
    ll cow2 = -row2 * (row2 - 1) / 2 + r;
    if (row2 > row1 + 1 || ((row2 == row1 + 1 && cow2 > cow1 - 1)))
    {
        ok = 0;
    }
    // for (ll i = l; i <= mid; i++)
    // {
    //     ll j = r + l - i;
    //     ll row1 = getrow(i);
    //     ll cow1 = -row1 * (row1 - 1) / 2 + i;
    //     ll row2 = getrow(j);
    //     ll cow2 = -row2 * (row2 - 1) / 2 + j;
    //     if (row2 > row1 + 1 || ((row2 == row1 + 1 && cow2 > cow1 - 1)))
    //     {
    //         ok = 0;
    //         break;
    //     }
    // }
    if (ok)
        cout << "YES\n";
    else
        cout << "NO\n";
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