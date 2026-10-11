#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f3f3f3f3f;
void solve()
{
    int n, q, p;
    char c;
    string s;
    cin >> n >> q;
    vector<ll> a(n + 1);
    vector<ll> sum(n + 1, 0);
    vector<ll> front_min(n + 1, INF);
    vector<ll> end_min(n + 2, INF);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cin >> s;
    s = ' ' + s;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '+')
            sum[i] = sum[i - 1] + a[i];
        else
            sum[i] = sum[i - 1] - a[i];
        front_min[i] = min(front_min[i - 1], sum[i]);
    }
    for (int i = n; i >= 1; i--)
    {
        end_min[i] = min(end_min[i + 1], sum[i]);
    }
    for (int i = 1; i <= q; i++)
    {
        cin >> p >> c;
        ll x = front_min[p - 1];
        ll y = end_min[p];
        if (c != s[p])
        {
            if (c == '+')
                y += 2 * a[p];
            else
                y -= 2 * a[p];
        }
        if (x >= 0 && y >= 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
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