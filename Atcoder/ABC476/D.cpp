#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 2e5 + 1;
ll a[N], b[N], c[N], pre_a[N], pre_b[N];
const int INF = 0x3f3f3f3f;
const ll INFF = 0x3f3f3f3f3f3f3f3f;
void solve()
{
    ll n, m, k, x, y;
    int ans = 0;
    int up = 0;
    cin >> n >> m >> k >> x >> y;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    for (int i = 1; i <= n; i++)
        pre_a[i] = pre_a[i - 1] + a[i];
    for (int i = 1; i <= m; i++)
    {
        int num = (b[i] + k - 1) / k;
        c[i] = c[i - 1] + num;
        pre_b[i] = num * k - b[i] + pre_b[i - 1];
        if (c[i] <= y)
            up = i;
        else
            break;
    }
    for (int i = 0; i <= up; i++)
    {
        ll rest = x + (y - c[i]) * k + pre_b[i];
        int l = 0, r = n;
        while (l < r)
        {
            int mid = l + ((r - l + 1) >> 1);
            if (pre_a[mid] <= rest)
                l = mid;
            else
                r = mid - 1;
        }
        ans = max(ans, i + l);
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