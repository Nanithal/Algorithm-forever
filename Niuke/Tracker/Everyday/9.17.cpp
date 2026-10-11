// https://www.nowcoder.com/practice/6283453737754229a17ccb19b406afb5?channelPut=tracker2
// 图论 有向边
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 2e5 + 1;
const int INF = 0x3f3f3f3f;
void solve()
{
    ll n, k, x, l, r;
    cin >> n >> k >> x;
    if (((n - 1) * x + 1 > k) || (k > (n + 1) * x - 1))
    {
        cout << -1 << endl;
        return;
    }
    l = x;
    r = n * x;
    k -= (n - 1) * x + 1;
    r += min(x - 1, k);
    k -= min(x - 1, k);
    l -= min(x - 1, k);
    k -= min(x - 1, k);
    if (l > 2e9 || r > 2e9)
    {
        cout << -1 << endl;
        return;
    }
    cout << l << ' ' << r << endl;
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