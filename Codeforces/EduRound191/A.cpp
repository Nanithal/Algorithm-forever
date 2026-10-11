#include <bits/stdc++.h>
using namespace std;
int n, x, y, z;
void solve()
{
    cin >> n >> x >> y >> z;
    int ans = ceil(n * 1.0 / (x + y));
    n -= z * x;
    if (n <= 0)
    {
        cout << ans << '\n';
        return;
    }
    else
    {
        int temp = z;
        temp += ceil(n * 1.0 / (x + 10 * y));
        ans = min(ans, temp);
        cout << ans << '\n';
        return;
    }
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
}