#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
const ll modnum = 1e9 + 7;
ll n, a, ans;
inline ll calculate(int x, int y)
{
    ll temp = 1;
    for (int i = x; i > x - y; i--)
        temp *= i;
    for (int i = 2; i <= y; i++)
        temp /= i;
    return temp;
}
void solve()
{
    map<ll, ll> line;
    cin >> n;
    ans = calculate(n, 2);
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        line[a]++;
    }
    for (auto &it : line)
    {
        if (it.second >= 2)
            ans -= calculate(it.second, 2);
    }
    ans %= modnum;
    for (int i = 3; i <= n; i++)
    {
        ans *= i;
        ans %= modnum;
    }
    // ans /= 2;    //这里不能除2，会破坏数据，可以在n!的时候从下标3开始
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