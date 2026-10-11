#include <bits/stdc++.h>
using namespace std;
int n;
void solve()
{
    int x, y;
    string a;
    cin >> x >> y >> a;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == 'f' && y <= n - 1)
            y++;
        else if (a[i] == 'b' && y >= 2)
            y--;
        else if (a[i] == 'l' && x >= 2)
            x--;
        else if (a[i] == 'r' && x <= n - 1)
            x++;
    }
    cout << x << ' ' << y << '\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> n >> t;
    while (t--)
    {
        solve();
    }
}