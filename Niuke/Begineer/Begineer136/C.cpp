#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
void solve()
{
    int n;
    ll x1, x2, y1, y2, ans;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    string s;
    cin >> s;
    ans = abs(x1 - x2) + abs(y1 - y2) + n;
    cout << ans << endl;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'L')
        {
            cout << (x1 <= x2 ? 'A' : 'B');
        }
        else if (s[i] == 'R')
        {
            cout << (x1 <= x2 ? 'B' : 'A');
        }
        else if (s[i] == 'U')
        {
            cout << (y1 <= y2 ? 'B' : 'A');
        }
        else
        {
            cout << (y1 <= y2 ? 'A' : 'B');
        }
    }
    cout << endl;
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