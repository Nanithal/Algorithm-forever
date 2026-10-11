#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
const ll maxn = 1e18;
ll fast_pow(ll x, ll n)
{
    ll res = 1;
    while (n)
    {
        if (n & 1)
        {
            if (res <= maxn / x)
                res *= x;
            else
                return 0;
        }
        if (n > 1)
        {
            if (x <= maxn / x)
                x *= x;
            else
                return 0;
        }

        n >>= 1;
    }
    return res;
}
void solve()
{
    ll p, q, now = 0, location;
    cin >> p >> q;
    location = 2;
    while (true)
    {
        now = fast_pow(p, q);
        if (!now)
            break;
        location++;
        p = q;
        q = now;
    }
    cout << location << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}