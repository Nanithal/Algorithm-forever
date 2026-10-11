#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int INF = 0x3f3f3f3f;

void solve()
{
    ll x;
    cin >> x;
    int i = 0, minn = INF, maxn = 0, num = 0;
    bool vis = false;
    while (x)
    {
        if (x & 1)
        {
            num++;
            maxn = i;
            if (!vis)
            {
                minn = i;
                vis = true;
            }
        }
        i++;
        x >>= 1;
    }
    if (!vis)
        cout << num << ' ' << -1 << ' ' << -1 << endl;
    else
        cout << num << ' ' << minn << ' ' << maxn << endl;
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