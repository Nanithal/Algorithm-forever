#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
void solve()
{
    int n, a, ans = 0;
    map<int, vector<int>> save;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        save[a].push_back(i);
    }
    for (auto &p : save)
    {
        if (p.second.size() >= 2)
        {
            if ((p.second[p.second.size() - 1] - p.second[0]) % 2 == 0)
                ans++;
        }
    }
    cout << ans;
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