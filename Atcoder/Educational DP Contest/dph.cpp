#include <bits/stdc++.h>

#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 1e3 + 1;
const int INF = 0x3f3f3f3f;
const ll INFF = 0x3f3f3f3f3f3f3f3f;
const ll MODD = 1e9 + 7;
ll dp[N][N];
string s[N];
void solve()
{
  int h, w;
  cin >> h >> w;
  for (int i = 1; i <= h; i++)
    cin >> s[i];
  dp[1][0] = 1;
  for (int i = 1; i <= h; i++)
  {
    for (int j = 1; j <= w; j++)
    {
      if (s[i][j - 1] == '#')
        dp[i][j] = 0;
      else
        dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MODD;
    }
  }
  cout << dp[h][w] << endl;
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
