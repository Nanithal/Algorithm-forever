#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 1;
int a[N];

void solve()
{
    int n, ans = 0;
    cin >> n;
    vector<int> pre(n + 1);
    pre[0] = -INF;
    vector<int> sa;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] > pre[i - 1])
            sa.push_back(i);
        pre[i] = max(pre[i - 1], a[i]);
    }
    for (int i = 0; i < sa.size() - 1; i++)
    {
        ans = max(sa[i + 1] - sa[i], ans);
    }
    cout << sa.size() << ' ' << ans << endl;
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