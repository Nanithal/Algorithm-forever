// https://www.nowcoder.com/practice/579b734002034f38a3af95e7843ae400?channelPut=tracker2

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
ll x, y;
void solve()
{
    cin >> x >> y;
    if (x == 0 || x == 1)
    {
        cout << -1 << endl;
        return;
    }
    if (y == 0)
    {
        cout << -1 << endl;
        return;
    }
    ll ans = 0, now = 1;
    while (now <= y / x) // 等价于now * x <= y
    {
        now *= x;
        ans++;
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