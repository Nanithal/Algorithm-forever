#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 2e5 + 1;
int n, m, a[N], d;
long long ans;
void solve()
{
    cin >> n >> m;
    ans = 0;
    vector<long long> sum(n + 1, 0);
    vector<int> b(m + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
    }
    sort(b.begin(), b.end());
    for (int i = 1; i <= m; i++)
    {
        ans += abs(sum[b[i]] - sum[b[i - 1]]);
    }
    ans += sum[n] - sum[b[m]];
    cout << ans << '\n';
    return;
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