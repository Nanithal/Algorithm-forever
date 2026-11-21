
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 2e5 + 1;
const int INF = 0x3f3f3f3f;
const ll INFF = 0x3f3f3f3f3f3f3f3f;

void solve()
{
  int n, a;
  cin >> n;
  vector<int> sa[n + 1];
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      cin >> a;
      sa[j].push_back(a);
    }
  }
  for (int i = 1; i <= n; i++)
    sort(sa[i].begin(), sa[i].end());
  bool ok = 1;
  for (int i = 0; i < n; i++)
  {
    for (int j = 2; j <= n; j++)
    {
      if (sa[j][i] < sa[j - 1][i])
      {
        ok = false;
        break;
      }
    }
  }
  if (ok)
    cout << "Yes\n";
  else
    cout << "No\n";
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
