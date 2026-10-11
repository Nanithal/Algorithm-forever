#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
ll n, ans;
void solve()
{
    ans = 20;
    cin >> n;
    for (int i = 0; i < 20; i++)
    {
        ll temp = 1 << (20 - i);
        ans = min(ans, (temp - n % temp) % temp + i);
    }
    cout << ans << endl;
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