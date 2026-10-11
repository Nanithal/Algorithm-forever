#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
void solve()
{
    int n, a, minn = 1e9 + 5, maxn = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        maxn = max(maxn, a);
        minn = min(minn, a);
    }
    cout << maxn - minn << ' ' << ((maxn + minn + 1) >> 1) << endl;
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