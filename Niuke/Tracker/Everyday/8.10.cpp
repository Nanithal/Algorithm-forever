// 若想要染红前i个数，最小代价可能处于染红大于等于前i个数的情况中，那么需要维护一个数组记录的是染红前i个位置的最小代价
// 同理，另开数组记录染红j-n位置的最小代价数组
// 然后滑动窗口+贪心

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
ll qian[300007], ho[300007], n, ans, q1[300007];
map<ll, ll> t;
void solve()
{
    cin >> n;
    qian[n + 1] = 9e18;
    ho[0] = 9e18;
    ans = 9e18;
    for (int i = 1; i <= n; i++)
    {
        cin >> q1[i];
        ho[i] = min(ho[i - 1], q1[i] * (n - i + 1));
    }
    for (int i = n; i >= 1; i--)
    {
        qian[i] = min(qian[i + 1], q1[i] * i);
    }
    int r = 1;
    for (int i = 0; i <= n; i++)
    {
        t[q1[i]]--;
        while (r <= n && !t[q1[r]])
        {
            t[q1[r]]++;
            r++;
        }
        ans = min(ans, qian[i] + ho[r]);
    }
    cout << ans;
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