#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, maxn;
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b;
        if (n >= a)
            maxn = max(maxn, b);
    }
    cout << n - maxn << endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}