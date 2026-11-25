
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
  string je, je1;
  vector<string> s(n + 1);
  for (int i = 1; i <= m; i++)
  {
    je.push_back('x');
    je1.push_back('0');
  }
  for (int i = 1; i <= n; i++)
    cin >> s[i];
  for (int i = 1; i <= n; i++)
  {
    if (s[i] == je)
    {
      cout << "Faucet " << i << endl;
      return;
    }
    else if (s[i] == je1)
      continue;
    else
    {
      for (int j = 0; j < m; j++)
      {
        if (s[i][j] == 'x')
        {
          cout << "Drain " << j + 1 << endl;
          return;
        }
      }
    }
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  // cin >> t;s
  while (t--)
  {
    solve();
  }
  return 0;
}
