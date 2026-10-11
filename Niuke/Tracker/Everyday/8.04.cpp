// https://www.nowcoder.com/practice/ae8aef7c828f4a12b846ee193fe268f2?channelPut=tracker2

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;

struct Edge
{
    int u, v;
};

void solve()
{
    int n;
    if (!(cin >> n))
        return;

    vector<Edge> edges(n + 1);
    vector<vector<pair<int, int>>> g(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> edges[i].u >> edges[i].v;
        g[edges[i].u].push_back({edges[i].v, i});
        g[edges[i].v].push_back({edges[i].u, i});
    }

    vector<int> d1(n + 1, INF);
    queue<int> q;
    d1[1] = 0;
    q.push(1);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto &e : g[u])
        {
            if (d1[e.first] == INF)
            {
                d1[e.first] = d1[u] + 1;
                q.push(e.first);
            }
        }
    }
    vector<int> dn(n + 1, INF);
    dn[n] = 0;
    q.push(n);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto &e : g[u])
        {
            if (dn[e.first] == INF)
            {
                dn[e.first] = dn[u] + 1;
                q.push(e.first);
            }
        }
    }

    int L1 = INF, L2 = INF;
    vector<int> path1_edges, path2_edges;

    vector<bool> vis_edge(n + 1, false);

    int curr = 1;
    L1 = d1[n];

    vector<int> deg(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        deg[edges[i].u]++;
        deg[edges[i].v]++;
    }
    queue<int> leaf;
    for (int i = 1; i <= n; i++)
    {
        if (deg[i] == 1)
            leaf.push(i);
    }
    while (!leaf.empty())
    {
        int u = leaf.front();
        leaf.pop();
        for (auto &e : g[u])
        {
            int v = e.first;
            if (deg[v] > 1)
            {
                deg[v]--;
                if (deg[v] == 1)
                    leaf.push(v);
            }
        }
    }
    vector<bool> in_loop(n + 1, false);
    for (int i = 1; i <= n; i++)
    {
        if (deg[edges[i].u] > 1 && deg[edges[i].v] > 1)
        {
            in_loop[i] = true;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int u = edges[i].u, v = edges[i].v;
        if (!in_loop[i])
        {
            bool is_on_path = false;
            if (d1[u] < d1[v])
                swap(u, v);
            if (dn[u] + d1[u] == d1[n] && d1[v] + 1 == d1[u])
            {
                is_on_path = true;
            }

            if (is_on_path)
            {
                cout << -1 << "\n";
            }
            else
            {
                cout << d1[n] << "\n";
            }
        }
        else
        {

            bool on_shortest = (d1[u] + 1 + dn[v] == d1[n]) || (d1[v] + 1 + dn[u] == d1[n]);
            if (!on_shortest)
            {
                cout << d1[n] << "\n";
            }
            else
            {

                int loop_cnt = 0;
                for (int j = 1; j <= n; j++)
                    if (in_loop[j])
                        loop_cnt++;

                cout << d1[n] + loop_cnt - 2 << "\n";
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}