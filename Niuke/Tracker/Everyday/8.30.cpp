#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int INF = 0x3f3f3f3f;
const ll INFF = 0x3f3f3f3f3f3f3f3f;
void solve()
{
    ll n, ans;
    cin >> n;
    vector<ll> a(n + 3, 0), b(n + 3, 0), pre(n + 1, 0), sur(n + 3, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    if (n <= 2)
    {
        cout << 0 << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > 0)
        {
            pre[i] = pre[i - 1] + a[i];
            a[i + 1] -= a[i];
            a[i + 2] -= a[i];
        }
        else
            pre[i] = pre[i - 1];
    }
    for (int i = n; i >= 2; i--)
    {
        if (b[i] > 0)
        {
            sur[i] = sur[i + 1] + b[i];
            b[i - 1] -= b[i];
            b[i - 2] -= b[i];
        }
        else
            sur[i] = sur[i + 1];
    }
    ans = pre[n];
    for (int i = 1; i <= n; i++)
        ans = min(ans, pre[i - 1] + sur[i + 2]);
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