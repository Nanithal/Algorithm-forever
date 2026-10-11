#include <bits/stdc++.h>
using namespace std;
const int N = 101;
long long a[N], n;
void solve()
{
    long long ans = 1e5;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    long long now = 1, i = 1;
    while (i <= n + 1)
    {
        if (i == n + 1)
        {
            ans = min(ans, max(now - 1, n - i + 1));
            now = i;
            i++;
        }
        if (a[i] == a[now])
            i++;
        else
        {
            ans = min(ans, max(now - 1, n - i + 1));
            now = i;
        }
    }
    cout << ans << '\n';
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