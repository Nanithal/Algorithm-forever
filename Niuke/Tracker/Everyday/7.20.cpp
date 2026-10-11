// 分组背包

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll NEG = -4e18;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, C, m;
    cin >> n >> C >> m;
    vector<ll> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
    }
    vector<int> pair_id(n + 1, 0);
    vector<int> pair_u(m + 1), pair_v(m + 1);
    vector<ll> pair_w(m + 1);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        pair_id[u] = pair_id[v] = i;
        pair_u[i] = u;
        pair_v[i] = v;
        pair_w[i] = w;
    }
    struct State
    {
        int cnt;
        ll cost;
        ll val;
    };
    vector<vector<State>> groups;
    for (int i = 1; i <= m; i++)
    {
        int u = pair_u[i], v = pair_v[i];
        vector<State> g;
        g.push_back({0, 0, 0});
        if (a[u] <= C)
            g.push_back({1, a[u], b[u]});
        if (a[v] <= C)
            g.push_back({1, a[v], b[v]});
        if (a[u] + a[v] <= C)
            g.push_back({2, a[u] + a[v], b[u] + b[v] + pair_w[i]});
        groups.push_back(g);
        pair_id[u] = pair_id[v] = -1;
    }
    for (int i = 1; i <= n; i++)
    {
        if (pair_id[i] == 0)
        {
            vector<State> g;
            g.push_back({0, 0, 0});
            if (a[i] <= C)
                g.push_back({1, a[i], b[i]});
            groups.push_back(g);
        }
    }
    vector<vector<ll>> dp(5, vector<ll>(C + 1, NEG));
    dp[0][0] = 0;

    for (auto &g : groups)
    {
        vector<vector<ll>> ndp = dp;
        for (int j = 0; j <= 4; j++)
        {
            for (int c = 0; c <= C; c++)
            {
                if (dp[j][c] == NEG)
                    continue;
                for (auto &st : g)
                {
                    int nj = j + st.cnt;
                    int nc = c + (int)st.cost;
                    if (nj > 4 || nc > C)
                        continue;
                    ndp[nj][nc] = max(ndp[nj][nc], dp[j][c] + st.val);
                }
            }
        }
        dp = move(ndp);
    }

    ll ans = 0;
    for (int j = 0; j <= 4; j++)
    {
        for (int c = 0; c <= C; c++)
        {
            ans = max(ans, dp[j][c]);
        }
    }

    cout << ans << '\n';
    return 0;
}