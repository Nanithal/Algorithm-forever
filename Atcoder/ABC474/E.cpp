#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;
const int INF = 0x3f3f3f3f;
using ll = long long;

class node
{
public:
    int a, b, c;
};
bool com(node a, node b)
{
    return a.c < b.c;
}
// 枚举
void solve()
{
    ll ans = LLONG_MAX, sum = 0;
    int n, minn = INF;
    cin >> n;
    vector<node> in(n + 1);
    vector<ll> pre(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> in[i].a >> in[i].b;
        minn = min(minn, in[i].a);
        sum += in[i].a;
        in[i].c = in[i].a - in[i].b;
    }
    sort(in.begin() + 1, in.end(), com);
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + in[n - i + 1].c;
    // 用k张优惠券来买，多的需要补的话就买最便宜的来补
    for (int k = 0; k <= n; k++)
    {
        ans = min(ans, sum - pre[k] + max(2 * k - n, 0) * minn);
    }
    cout << ans << endl;
    // int p1 = 1, p2 = n;
    // while (p1 < p2)
    // {
    //     ans -= in[p2].c;
    //     p1++, p2--;
    // }
    // if (n & 1)
    // {
    //     if (minn < in[(n + 1) / 2].c)
    //         ans -= (in[(n + 1) / 2].c - minn);
    // }
    // cout << ans << endl;
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