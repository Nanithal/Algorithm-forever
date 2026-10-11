#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
const int N = 2e5 + 1;
class point
{
public:
    int x, y;
    bool operator<(const point &other) const
    {
        if (x != other.x)
            return x < other.x;
        return y < other.y;
    }
};
void solve()
{
    int maxn = 0, cow = 0, row = 0, n, x, y;
    map<point, int> save;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x >> y;
        if (x - 1 > 0 && y - 2 > 0)
            save[{x - 1, y - 2}]++;
        if (x - 1 > 0)
            save[{x - 1, y + 2}]++;
        if (x - 2 > 0 && y - 1 > 0)
            save[{x - 2, y - 1}]++;
        if (x - 2 > 0)
            save[{x - 2, y + 1}]++;
        if (y - 1 > 0)
            save[{x + 2, y - 1}]++;
        if (y - 2 > 0)
            save[{x + 1, y - 2}]++;
        save[{x + 2, y + 1}]++;
        save[{x + 1, y + 2}]++;
    }
    for (auto &p : save)
    {
        if (p.second > maxn)
        {
            maxn = p.second;
            cow = p.first.x;
            row = p.first.y;
        }
    }
    cout << cow << ' ' << row << endl;
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