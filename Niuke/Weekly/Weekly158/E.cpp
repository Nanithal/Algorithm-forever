#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 1;
int a[N], sa[N];
int n, q, p, x, opt, l, r;
void solve()
{
    cin >> n >> q;
    vector<int> pre(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 2; i < n; i++)
    {
        pre[i] = pre[i - 1];
        if ((a[i] - a[i - 1]) < (a[i + 1] - a[i]))
            pre[i] += 1;
    }
    for (int i = 1; i <= q; i++)
    {
        cin >> opt;
        if (opt & 1)
        {
            cin >> p >> x;
            a[p] = x;
            if (p == 1)
            {
                if ((a[2] - a[1]) < (a[3] - a[2]))
                    continue;
                else
                    pre[2] -= 1;
            }
            if (p == n)
            {
                if ((a[n - 1] - a[n - 2]) < (a[n] - a[n - 1]))
                    continue;
                else
                    pre[n - 1] -= 1;
            }
            else
            {
                if (p != 2)
                {
                                }
            }
        }
        else
        {
            cin >> l >> r;
            cout << pre[r - 1] - pre[l + 1] << endl;
        }
    }
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