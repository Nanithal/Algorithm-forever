#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n, m;
void solve()
{
    cin >> n >> m;
    vector<int> a(n + 1, 0);
    vector<int> b(m + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    if (n < 2 * m)
    {
        cout << "NO" << endl;
        return;
    }
    bool ok = 1;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i = 1; i <= m; i++)
    {
        if (a[i] >= b[i])
        {
            ok = 0;
            break;
        }
    }
    if (!ok)
    {
        cout << "NO" << endl;
        return;
    }
    for (int i = n; i >= n - m + 1; i--)
    {
        if (a[i] <= b[i - n + m])
        {
            ok = 0;
            break;
        }
    }
    if (ok)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return;
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