#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
const ll Mod = 1e9 + 7;
void solve()
{
    int n;
    ll ans = 0, sum = 0;
    string s;
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        int nu = s[i] - '0';
        if (!(nu & 1))
        {
            ans = (ans + sum + 1) % Mod;
        }
        sum = (sum * 2) % Mod;
        if(nu)
        {
            sum = (sum + 1) % Mod;
        }
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