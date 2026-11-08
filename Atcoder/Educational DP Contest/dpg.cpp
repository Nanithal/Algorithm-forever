#include <bits/stdc++.h>

#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 1e5 + 1;
const int INF = 0x3f3f3f3f;
const ll INFF = 0x3f3f3f3f3f3f3f3f;

// // 递归查找的思想，会超时
// vector<vector<int>> reach(N);
// int ans = 0;

// void find(int loc, int len)
// {
//   for (auto &p : reach[loc])
//   {
//     find(p, len + 1);
//   }
//   ans = max(ans, len);
// }

// void solve()
// {
//   int n, m;
//   cin >> n >> m;
//   for (int i = 1; i <= m; i++)
//   {
//     int x, y;
//     cin >> x >> y;
//     reach[x].push_back(y);
//   }
//   for (int i = 1; i <= n; i++)
//     find(i, 0);
//   cout << ans << endl;
// }

// DFS + 记忆化搜索的dp
// dp[u]指的是从顶点u出发的最长路径长度
// int dp[N], n, m;
// vector<int> e[N];
// int dfs(int u)
// {
//   if (dp[u] != -1)
//     return dp[u];
//   dp[u] = 0;
//   for (int v : e[u])
//     dp[u] = max(dp[u], dfs(v) + 1);
//   return dp[u];
// }
// void init()
// {
//   for (int i = 1; i <= n; i++)
//     dp[i] = -1;
// }
// void solve1()
// {
//   cin >> n >> m;
//   for (int i = 1; i <= m; i++)
//   {
//     int u, v;
//     cin >> u >> v;
//     e[u].push_back(v);
//   }
//   init();
//   int ans = 0;
//   for (int i = 1; i <= n; i++)
//     ans = max(ans, dfs(i));
//   cout << ans << endl;
// }

// dp[u]代表以顶点u为终点的最长路径长度
// dp[v] = max(do[v], dp[u] + 1)
// +拓扑排序
vector<int> e[N];
int indeg[N], dp[N];
int n, m;
queue<int> q;
void push_queue()
{
  for (int i = 1; i <= n; i++)
  {
    if (indeg[i] == 0)
      q.push(i);
  }
}
void solve2()
{
  cin >> n >> m;

  for (int i = 1; i <= m; i++)
  {
    int u, v;
    cin >> u >> v;
    e[u].push_back(v);
    indeg[v]++;
  }
  push_queue();
  int ans = 0;
  while (!q.empty())
  {
    int u = q.front();
    q.pop();

    for (int v : e[u])
    {
      // DAG上的最长路径dp
      dp[v] = max(dp[v], dp[u] + 1);

      // 拓扑排序
      indeg[v]--;

      if (indeg[v] == 0)
        q.push(v);
    }
    ans = max(ans, dp[u]);
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
    solve2();
  }
  return 0;
}
