#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n,m,a,k;
    cin >> n >> m >> k;
    int up = n * m;
    unordered_map<int, vector<int>>sa;
    for(int i = 1; i <= up;i++)
    {
        cin >> a;
        sa[(a + m - 1)/m].push_back(i);
    }
    if (k >= m)
    {
        cout << m << endl;
        return;
    }
    int ans = 0x3f3f3f3f;
    for(auto &p:sa)
    {
        ans = min(max(p.second[m-k-1],m),ans);
    }
    cout << ans << endl;
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