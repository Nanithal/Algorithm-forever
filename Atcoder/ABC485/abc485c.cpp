
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 3e5 + 1;
const int INF = 0x3f3f3f3f;
const ll INFF = 0x3f3f3f3f3f3f3f3f;

int c[N];

void solve()
{
  int n;
  cin >> n;
  vector<pair<int, int>> sa;
  for (int i = 1; i <= n; i++)
    cin >> c[i];
  int l = 1;
  for (int i = 1; i <= n; i++)
  {
    while (i <= n && c[i] == c[l])
    {
      i++;
    }
    i--;
    sa.push_back({l, i});
    l = i + 1;
  }
  for (auto p : sa)
  {
    for (int i = p.first; i <= p.second; i++)
    {
      int d1 = INF, d2 = INF;
      if (p.first - 1 > 0)
        d1 = i - p.first + 1;
      if (p.second + 1 <= n)
        d2 = p.second + 1 - i;
      cout << min(d1, d2) << ' ';
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
