// https://www.nowcoder.com/practice/6a0cbe6d000f486bb9b4845fc50f59ce?channelPut=tracker2
// 关键在于于优惠券的使用策略
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 2e5 + 1;
const int INF = 0x3f3f3f3f;
void solve()
{
    int n, a, b, x, y;
    ll sum = 0;
    cin >> n >> a >> b >> x >> y;
    vector<ll> in(n);
    for (auto &p : in)
    {
        cin >> p;
        sum += p * 100;
    }
    int m = min(n, a + b);
    sort(in.begin(), in.end(), greater<ll>());
    vector<ll> d;
    ll save = 0;
    for (int i = 0; i < m; i++)
    {
        ll save2 = min(in[i], (ll)y) * 100;
        ll save1 = in[i] * (100 - x);
        save += save2;
        d.push_back(save1 - save2);
    }
    sort(d.begin(), d.end(), greater<ll>());
    vector<ll> pre(m + 1, 0);
    for (int i = 0; i < m; i++)
        pre[i + 1] = pre[i] + d[i];
    int low = max(0, m - b);
    int high = min(a, m);

    ll best = LLONG_MIN;
    for (int k = low; k <= high; k++)
    {
        best = max(best, pre[k]);
    }
    ll ans = sum - save - best;
    cout << fixed << setprecision(10) << ans / 100.0 << endl;
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