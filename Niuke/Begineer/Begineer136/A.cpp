#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << a - 1 << ' ' << b - 1 << ' ' << c - 1 << ' ';
    cout << a + 1 << ' ' << b + 1 << ' ' << c + 1 << ' ';
    cout << endl;
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