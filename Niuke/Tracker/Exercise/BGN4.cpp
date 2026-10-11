#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
void solve()
{
    int n, ans = INF;
    cin >> n;
    for (int i = 0; i <= n / 6; i++)
    {
        int j = (n - i * 6);
        if (j % 8 == 0)
        {
            ans = min(ans, i + j / 8);
        }
    }
    if (ans != INF)
        cout << ans << endl;
    else
        cout << -1 << endl;
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