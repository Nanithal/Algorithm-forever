#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 1;
int a[N];
ll n, m;

ll sim()
{
    ll res = 0;
    for (int i = 1; i <= n; i++)
    {
        res = (a[i] + res * 10) % m;
    }
    return res;
}
void solve()
{
    int ans = 0;
    cin >> n >> m;
    string s;
    cin >> s;
    s = ' ' + s;
    for (int i = 1; i <= n; i++)
        a[i] = s[i] - '0';
    if (sim() == 0)
        ans++;
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= n; j++)
            a[j] = (a[j] + 1) % 10;
        if (sim() == 0)
            ans++;
    }
    cout << ans << endl;
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