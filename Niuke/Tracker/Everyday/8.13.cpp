#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
void solve()
{
    int n, a, maxn = -1, ans;
    bool ok = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        if (a & 1)
            ok = 1;
        maxn = max(maxn, a);
    }
    if (!ok)
        ans = maxn / 2 - n;
    else
        ans = maxn - n;
    if (ans & 1)
        cout << "Alice" << endl;
    else
        cout << "Bob" << endl;
    return;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}