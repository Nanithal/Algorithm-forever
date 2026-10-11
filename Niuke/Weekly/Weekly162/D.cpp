#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 1;
char c[61];

void solve()
{
    ll ans = 0;
    int n;
    cin >> n >> c[0];
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
        ans = ans * 2;
        if (c[i] == c[0])
            ans += 1;
    }
    cout << ans * 2 << endl;
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