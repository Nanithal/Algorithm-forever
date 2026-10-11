#include <bits/stdc++.h>
using namespace std;
const int N = 2001;
long long a[N], b[N], maxn1, maxn2, minn1, minn2;
int n;
void solve()
{
    maxn1 = maxn2 = -1;
    minn1 = minn2 = 1e10;
    long long ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        maxn1 = max(maxn1, a[i]);
        minn1 = min(minn1, a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        maxn2 = max(maxn2, b[i]);
        minn2 = min(minn2, b[i]);
    }
    if (minn1 > minn2 || maxn1 > maxn2)
    {
        cout << -1 << '\n';
        return;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
