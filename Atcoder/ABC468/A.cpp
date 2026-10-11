#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
int n, a[101];
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int ans = 0;
    for (int i = 2; i <= n - 1; i++)
    {
        if (a[i] > a[i - 1] && a[i] > a[i + 1])
            ans++;
    }
    cout << ans << endl;
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