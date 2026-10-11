// https://codeforces.com/contest/2264/problem/A
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 2e5 + 1;
const int INF = 0x3f3f3f3f;
const ll INFF = 0x3f3f3f3f3f3f3f3f;
ll a[N];
void solve()
{
    int n, m;
    ll sum = 0, ans = -INFF;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    priority_queue<int> sa;
    for (int i = 1; i <= m - 1; i++)
    {
        sa.push(a[i]);
        sum += a[i];
    }
    for (int i = m; i <= n; i++)
    {
        ans = max(ans, m * a[i] - sum);
        if (!sa.empty())
        {

            ll temp = sa.top();
            if (a[i] < temp)
            {
                sum -= (temp - a[i]);
                sa.pop();
                sa.push(a[i]);
            }
        }
    }
    cout << ans << endl;
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