
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
  int n, m;
  cin >> n >> m;
  string p, q;
  cin >> p >> q;
  vector<int> num_p(26), num_q(26);
  for (int i = 0; i < n; i++)
    num_p[p[i] - 'a']++;
  for (int i = 0; i < m; i++)
    num_q[q[i] - 'a']++;
  bool ok = 1;
  for (int i = 0; i < 26; i++)
  {
    char c = 'a' + i;
    if (c == 's' || c == 'i' || c == 'x')
    {
      if (num_p[i] - num_q[i] != 1)
      {
        ok = false;
        break;
      }
    }
    else
    {
      if (num_p[i] != num_q[i])
      {
        ok = false;
        break;
      }
    }
  }
  if (ok)
    cout << "YES\n";
  else
    cout << "NO\n";
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
