#include <bits/stdc++.h>
using namespace std;
int x, a, b;
void solve()
{
    cin >> x;
    if (x == 100)
    {
        cout << 9 << ' ' << 91 << '\n';
    }
    else if (x == 99)
    {
        cout << 9 << ' ' << 90 << '\n';
    }
    else
    {
        if (x % 10 != 9)
            a = 90 + x % 10 + 1;
        else
        {
            a = 90;
        }
        b = x - a;
        cout << a << ' ' << b << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}