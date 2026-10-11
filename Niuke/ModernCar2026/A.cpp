#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;
int n, m, x;
void solve()
{
    cin >> n >> m;
    map<int, priority_queue<int>> b;
    map<int, priority_queue<int, vector<int>, greater<int>>> c;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        b[x].push(i);
        c[x].push(i);
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> x;
        cout << b[x].size() << ' ';
        if (b[x].size())
        {
            cout << c[x].top() << ' ' << b[x].top();
        }
        cout << '\n';
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