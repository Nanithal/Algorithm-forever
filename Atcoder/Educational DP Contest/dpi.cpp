#include <bits/stdc++.h>

#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 3000;
const int INF = 0x3f3f3f3f;
const ll INFF = 0x3f3f3f3f3f3f3f3f;

double dp[N][N]; // dp[i][j]代表抛掷前i枚硬币时恰好有j枚硬币为正面
double p[N];
void solve()
{
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> p[i];
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      dp[i][j] += dp[i - 1][j] *
                  (1 - p[i]); // 第i枚抛掷出现了反面// 第 i 枚硬币出现正面
      if (j > 0)
        dp[i][j] += dp[i - 1][j - 1] * p[i]; // 第i枚抛掷出现了正面
    }
  }
  double ans = 0;
  for (int i = (n + 1) / 2; i <= n; i++)
    ans += dp[n][i];
  cout << fixed << setprecision(12) << ans
       << endl; // 注意：这里要控制输出的格式，否则会wa
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
