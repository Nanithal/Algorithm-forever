#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e9 / 2 + 5;
ll binPow(ll a, int k)
{
    ll ans = 1;
    while (k)
    {
        if (k & 1)
            ans = ans * a % MOD;
        a = a * a % MOD;
        k >>= 1;
    }
    return ans;
}
void solve()
{
    int n, maxn;
    cin >> n;
    ll ans = binPow(4LL, n);
    ans = (ans + (binPow(4LL, n / 2) * binPow(2LL, n % 2) - binPow(2, (n + 1) / 2) + MOD) % MOD) % MOD;
    cout << ans << '\n';
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