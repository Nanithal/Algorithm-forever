#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
ll a, b, x, nums, maxn, minn;
void solve()
{
    nums = 0;
    cin >> a >> b >> x;
    if (a == b)
    {
        cout << nums << '\n';
        return;
    }
    maxn = max(a, b);
    minn = min(a, b);
    nums = maxn - minn;
    for (ll i = 1; maxn != minn; i++)
    {
        maxn = floor(1.0 * maxn / x);
        ll temp1 = maxn, temp2 = minn;
        maxn = max(temp1, temp2);
        minn = min(temp1, temp2);
        nums = min(nums, maxn - minn + i);
        if (x > maxn)
        {
            if (minn * maxn == 0)
            {
                if (minn != 0)
                {
                    nums = min(nums, i + 1);
                }
                if (maxn != 0)
                {
                    nums = min(nums, i + 1);
                }
            }
            else
            {
                nums = min(nums, i + 2);
            }
        }
    }
    cout << nums << '\n';
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}