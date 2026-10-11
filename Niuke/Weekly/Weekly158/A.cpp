#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << 4 * abs(a - b) + 2 * abs(b - c) + abs(c - a) << endl;
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