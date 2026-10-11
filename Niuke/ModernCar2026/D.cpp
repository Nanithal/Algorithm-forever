#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;
int a[N];
long long sum[N], maxn, minn, ans;
int n, m, k;
void solve()
{
    cin >> n >> k >> m;
    ans = 0;
    priority_queue<int, vector<int>, greater<int>> b;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ans += a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    for (int i = 0; i <= n - k; i++)
    {
        b.push(sum[i + k] - sum[i]);
    }
    while (m)
    {
        long long temp = b.top();
        b.pop();
        b.push(temp + 2);
        m -= 1;
    }
    cout << ans + b.top() << '\n';
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