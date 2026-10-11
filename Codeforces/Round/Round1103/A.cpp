#include <bits/stdc++.h>
using namespace std;
int n, a;
void solve()
{
    cin >> n;
    int minn = 7;
    int maxn = -1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        maxn = max(maxn, a);
        minn = min(minn, a);
    }
    cout << maxn + 1 - minn << '\n';
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