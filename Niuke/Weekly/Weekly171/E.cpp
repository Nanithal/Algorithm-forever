
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 5005;
const int INF = 0x3f3f3f3f;
const ll INFF = 0x3f3f3f3f3f3f3f3f;

bool visited[N];
vector<vector<int>> ma(N);

void dfs(int p, int &num)
{
  num++;
  visited[p] = true;
  for (auto q : ma[p])
  {
    if (!visited[q])
      dfs(q, num);
  }
}

void solve()
{
  int n, m, s, u, v;
  cin >> n >> m >> s;
  for (int i = 1; i <= m; i++)
  {
    cin >> u >> v;
    ma[u].push_back(v);
  }
  int ans = 0;
  dfs(s, ans);
  cout << ans << endl;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  //   cin >> t;
  while (t--)
  {
    solve();
  }
  return 0;
}
