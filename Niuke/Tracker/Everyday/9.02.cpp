// https://www.nowcoder.com/practice/1ae57482db684866b918c66dbc36cb97?channelPut=tracker2
// 数论，分块思想

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int INF = 0x3f3f3f3f;

ll cal(ll n)
{
    ll res = 0;
    for (ll l = 1, r; l <= n; l = r + 1)
    {
        ll v = n / l;
        r = n / v;
        res += (r - l + 1) * v;
    }
    return res;
}
void solve()
{
    ll l, r;
    cin >> l >> r;
    cout << cal(r) - cal(l - 1);
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