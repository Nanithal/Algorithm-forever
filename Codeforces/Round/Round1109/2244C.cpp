#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;
int a, n, x, y;
void solve()
{
    cin >> n >> x >> y;
    int g = __gcd(x, y);
    bool ok = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        if (a != i)
        {
            if (abs(a - i) % g == 0)
                continue;
            ok = 0;
        }
    }
    if (ok)
        cout << "YES\n";
    else
        cout << "NO\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
