// https://atcoder.jp/contests/dp/tasks/dp_f

#include <bits/stdc++.h>

#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 3e3 + 1;
const int INF = 0x3f3f3f3f;
const ll INFF = 0x3f3f3f3f3f3f3f3f;

// 以字符串作为dp的话，内存会超限制
// string dp[N][N];
// void solve()
// {
//   string s, t;
//   cin >> s >> t;
//   int size_s = s.size();
//   int size_t = t.size();
//   s = ' ' + s;
//   t = ' ' + t;
//   for (int i = 1; i <= size_s; i++)
//   {
//     for (int j = 1; j <= size_t; j++)
//     {
//       if (s[i] == t[j])
//         dp[i][j] = dp[i - 1][j - 1] + s[i];
//       else
//         dp[i][j] = (dp[i][j - 1].size() >= dp[i - 1][j].size()) ? dp[i][j -
//         1]
//                                                                 : dp[i -
//                                                                 1][j];
//     }
//   }
//   cout << dp[size_s][size_t] << endl;
// }

int dp[N][N];
void solve1()
{
  string s, t;
  cin >> s >> t;
  int size_s = s.size();
  int size_t = t.size();
  s = ' ' + s;
  t = ' ' + t;
  for (int i = 1; i <= size_s; i++)
  {
    for (int j = 1; j <= size_t; j++)
    {
      if (s[i] == t[j])
        dp[i][j] = dp[i - 1][j - 1] + 1;
      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }
  string ans = "";
  int i = size_s, j = size_t;
  while (i > 0 && j > 0)
  {
    if (s[i] == t[j])
    {
      ans += s[i];
      i--;
      j--;
    }
    else if (dp[i - 1][j] >= dp[i][j - 1])
      i--;
    else
      j--;
  }
  reverse(ans.begin(), ans.end());
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
    solve1();
  }
  return 0;
}
