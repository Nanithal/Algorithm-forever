#include <bits/stdc++.h>
using namespace std;
int n, k;
void solve()
{
    cin >> n >> k;
    for (int i = 1; i < k; i++)
        cout << k << ' ' << i << endl;
    for (int i = k + 1; i <= n; i++)
        cout << k << ' ' << i << endl;
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