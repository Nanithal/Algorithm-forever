#include <bits/stdc++.h>
long long ans, n, x, y, k, minn, maxn;
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ans = 0;
        cin >> n >> x >> y >> k;
        minn = min(x, y);
        maxn = max(x, y);
        long long a = maxn - minn;
        long long b = minn + n - maxn;
        ans += min(a, b);
        if (n > 3)
            ans += k;
        cout << ans << '\n';
    }
    return 0;
}