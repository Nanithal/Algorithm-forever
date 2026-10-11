#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int INF = 0x3f3f3f3f;
void solve()
{
    int ans = INF;
    int n, m, x, y, k, save;
    cin >> n >> m >> x >> y >> k;
    save = k;
    for (int i = 0; i <= n; i++)
    {
        k = save;
        int con = min(k, min(n - i, i / 2));
        k -= con;
        int rel = i + con;
        if (rel >= n)
        {
            int j = m - min(k, m / 4);
            ans = min(ans, x * i + y * j);
        }
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