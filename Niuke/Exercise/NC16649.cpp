#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 1e4 + 1;
int a[N], n, m, l, r;
void solve()
{
    int ans = 0, orig = 0, sum = 90;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> l >> r;
        a[l]++;
        a[r + 1]--;
    }
    for (int i = 0; i <= n; i++)
    {
        sum += a[i];
        if (sum > 0)
        {
            ans += i - orig;
            orig = i + 1;
        }
    }
    ans += n - orig;
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