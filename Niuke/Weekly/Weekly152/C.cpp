#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int INF = 0x3f3f3f3f;

void solve()
{
    int n, x, y;
    cin >> n;
    vector<vector<int>> sa(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> x >> y;
        sa[x].push_back(y);
        sa[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
    {
        if (sa[i].size() == 1)
        {
            cout << i << ' ' << sa[i][sa[i].size() - 1] << endl;
            break;
        }
    }
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