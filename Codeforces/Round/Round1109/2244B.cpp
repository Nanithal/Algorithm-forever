#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;
int a[N], n;
void solve()
{
    bool ok = 1;
    int sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (i > a[i] && sum < i - a[i])
        {
            ok = 0;
        }
        sum += a[i] - i;
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