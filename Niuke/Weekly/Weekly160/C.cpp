#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int INF = 0x3f3f3f3f;

void solve()
{
    ll x;
    cin >> x;
    ll l = 0, r = 1e9;
    while (l < r)
    {
        ll mid = l + ((r - l + 1) >> 1);
        if (mid * mid > x)
            r = mid - 1;
        else
            l = mid;
    }
    cout << l << ' ' << x - l * l << ' ' << (l + 1) * (l + 1) - x << endl;
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