#include <bits/stdc++.h>
using namespace std;
const int N = 101;
int b[N], n, sum, minn, maxn;
class d
{
public:
    int v;
    int index;
} a[N];
bool com(d a, d b)
{
    return a.v <= b.v;
}
void solve()
{
    cin >> n;
    sum = 0, minn = 1e6, maxn = -1;
    vector<bool> vis(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].v;
        b[i] = a[i].v;
        a[i].index = i;
        minn = min(minn, a[i].v);
        maxn = max(maxn, a[i].v);
        sum += a[i].v;
    }
    if (minn == maxn)
    {
        cout << sum << '\n';
        return;
    }
    sort(a + 1, a + n + 1, com);
    for (int i = 1; i <= n; i++)
    {
        int index = a[i].index;
        if (!vis[index])
        {
            for (int j = index; j <= n; j++)
            {
                if (vis[j])
                    break;
                vis[j] = 1;
                sum -= max(0, b[j] - b[index]);
            }
        }
    }
    cout << sum << '\n';
    return;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}