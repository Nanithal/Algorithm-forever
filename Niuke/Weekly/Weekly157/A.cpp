#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
void solve()
{
    int a, b;
    cin >> a >> b;
    if (a + b == 10)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}