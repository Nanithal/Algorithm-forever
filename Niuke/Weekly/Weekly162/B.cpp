#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int INF = 0x3f3f3f3f;

void solve()
{
    ll ans = 0;
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    if (x > 1 && y > 1)
        ans += 2 * (x + y - 2);
    if (n > x && y > 1)
        ans += 2 * (n + y - 1 - x);
    if (x > 1 && m > y)
        ans += 2 * (x - 1 + m - y);
    if (n > x && m > y)
        ans += 2 * (n - x + m - y);
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