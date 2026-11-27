
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 2e5 + 1;
const int INF = 0x3f3f3f3f;
const ll INFF = 0x3f3f3f3f3f3f3f3f;

struct node
{
  char c;
  int x, y;
};

bool com(node a, node b)
{
  if (a.c < b.c)
    return true;
  if (a.c == b.c)
  {
    if (a.y < b.y)
      return true;
    if (a.y == b.y)
    {
      if (a.x > b.x)
        return true;
      return false;
    }
    return false;
  }
  return false;
}

void solve()
{
  int n, m;
  cin >> n >> m;
  vector<node> sa;
  for (int i = 1; i <= n; i++)
  {
    char c;
    for (int j = 1; j <= m; j++)
    {
      cin >> c;
      if (c >= 'A' && c <= 'Z')
        sa.push_back({c, i, j});
    }
  }
  sort(sa.begin(), sa.end(), com);
  for (auto p : sa)
    cout << p.x << ',' << p.y << endl;
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
