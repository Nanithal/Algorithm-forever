#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
void solve()
{
    int n, a;
    ll ans = 0;
    cin >> n;
    map<int, vector<int>> sa;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        sa[a].push_back(i);
    }
    for (auto &p : sa)
    {
        if (p.second.size() & 1)
        {
            ans += p.second[p.second.size() / 2];
        }
    }
    cout << ans << endl;
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