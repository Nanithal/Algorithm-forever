#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    bool ok = 1;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        if (a[i] <= i / 11 * 10 || a[i] > (i + 9) / 10 * 10)
        {
            ok = 0;
            break;
        }
    }
    if (ok)
        cout << "Yes\n";
    else
        cout << "No\n";
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