#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
const int N = 2e5 + 1;
ll a[N], pre[N], b[N];
ll n, q, x, k;
bool com(int c, int d)
{
    return c > d;
}
void solve()
{
    ll sum = 0;
    cin >> n >> q >> x;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = abs(a[i] - x);
        sum += b[i];
    }
    sort(b + 1, b + n + 1, com);
    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] + b[i];
    }
    for (int i = 1; i <= q; i++)
    {
        cin >> k;
        ll goal = sum - k;
        int l = 0, r = n;
        while (l < r)
        {
            int mid = l + ((r - l) >> 1);
            if (pre[mid] < goal)
                l = mid + 1;
            else
                r = mid;
        }
        cout << l << endl;
    }
    return;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >>t;
    while (t--)
    {
        solve();
    }
    return 0;
}