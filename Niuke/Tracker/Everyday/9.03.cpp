

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int INF = 0x3f3f3f3f;
const ll INFF = 0x3f3f3f3f3f3f3f3f;

void solve()
{
    int n;
    cin >> n;
    ll maxy = -INF, maxx = 0, minx = INFF, miny = INFF;
    for (int i = 1; i <= n; i++)
    {
        ll a;
        cin >> a;
        ll x = 1ll * i * i + a * a;
        ll y = 1ll * i * i - a * a;
        maxx = max(maxx, x);
        minx = min(minx, x);
        maxy = max(maxy, y);
        miny = min(miny, y);
    }
    cout << max(maxx - minx, maxy - miny) << endl;
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