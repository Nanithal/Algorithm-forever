#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int INF = 0x3f3f3f3f;

void solve()
{
    int n, l = 1, r = 0;
    cin >> n;
    map<int, int> sa;
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        sa[t]++;
        // r = max(r, sa[t]);
    }
    r = n; // 原版上界开小了而过不去
    if (sa.size() == n)
    {
        cout << 0 << endl;
        return;
    }
    while (l < r)
    {
        int mid = l + ((r - l) >> 1);
        int up = -INF;
        bool ok = 1;
        for (auto &it : sa)
        {
            if (it.first - mid > up)
            {
                up = it.first - mid + it.second - 1;
                if (up > it.first + mid)
                {
                    ok = 0;
                    break;
                }
            }
            else
            {
                up = it.second + up;
                if (up > it.first + mid)
                {
                    ok = 0;
                    break;
                }
            }
        }
        if (ok)
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << endl;
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