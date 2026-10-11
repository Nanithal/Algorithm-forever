#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int INF = 0x3f3f3f3f;

void solve()
{
    string x;
    cin >> x;
    cout << x << x << endl;
}
void solve1()
{
    ll x, y, sa, base = 1;
    int weishu = 0;
    cin >> x;
    sa = x;
    while (x)
    {
        x /= 10;
        weishu++;
    }
    x = sa;
    for (int i = 1; i <= weishu; i++)
        base *= 10;
    y = x * base + x;
    cout << y << endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve1();
    }
    return 0;
}