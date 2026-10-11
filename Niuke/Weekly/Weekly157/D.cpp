#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
void solve()
{
    ll n, k, ans = -1, l, r;
    cin >> n >> k;
    vector<ll> sum(n + 1, 0);
    vector<ll> h(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
        if (i != 1)
            sum[i] = sum[i - 1] + abs(h[i] - h[i - 1]);
    }
    l = r = 1;
    while (l <= n && r <= n + 1)
    {
        if (n - l <= ans)
            break;
        while (sum[r] - sum[l] <= k && r <= n)
        {
            r++;
        }
        ans = max(ans, r - l);
        l++;
    }
    cout << ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}