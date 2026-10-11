#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
using ll = long long;
ll w[N], a[N], b[N];
void solve()
{
    int n;
    cin >> n;
    bool ok = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        if (!ok && b[i] < a[i])
            ok = 1;
    }
    if (!ok)
    {
        cout << "No\n";
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] <= b[i])
            w[i] = 1;
        else
            w[i] = 1e18;
    }
    cout << "Yes\n";
    for (int i = 1; i <= n; i++)
        cout << w[i] << ' ';
    cout << endl;
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