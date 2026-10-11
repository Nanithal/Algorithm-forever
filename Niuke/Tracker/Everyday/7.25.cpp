// 二分答案
// 每一棵树砍伐所能带来的收益为h方-y方，y为最后这棵树的高度，h为原本的高度

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll m;
void solve()
{

    cin >> n >> m;
    vector<ll> h(n), c(n);
    ll sumH = 0, maxCut = 0;
    ll minC = 1e18, maxH = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> h[i] >> c[i];
        sumH += h[i];
        maxCut += h[i] - c[i];
        minC = min(minC, c[i]);
        maxH = max(maxH, h[i]);
    }

    m = min(m, maxCut);

    auto check = [&](ll H) -> bool // Lambda表达式写法  [&]代表引用捕获，可以直接按访问当前函数的所有局部变量
    {
        ll total = 0;
        for (int i = 0; i < n; i++)
        {
            if (h[i] > H)
            {
                total += h[i] - max(H, c[i]);
                if (total > m)
                    return false; // 提前退出
            }
        }
        return total <= m;
    };

    // 二分最小的 R，使得 cut(R) <= m
    ll L = minC - 1, R = maxH + 1;
    while (L + 1 < R)
    {
        ll mid = L + (R - L) / 2;
        if (check(mid))
            R = mid;
        else
            L = mid;
    }

    ll ans = 0, cut = 0;
    for (int i = 0; i < n; i++)
    {
        if (h[i] > R)
        {
            ll x = h[i] - max(R, c[i]);
            cut += x;
            ans += x * (2 * h[i] - x);
        }
    }

    ll rem = m - cut;
    if (rem > 0)
    {
        ans += rem * (2 * R - 1);
    }

    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}