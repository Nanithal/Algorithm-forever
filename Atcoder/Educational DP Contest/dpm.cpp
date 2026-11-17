#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;

const int N = 101;
const int K = 1e5 + 1;
const int MOD = 1e9 + 7;

int a[N];
int dp[N][K]; // dp[i][j]代表j枚糖果分给前i个人的方案数
int pre[K];

void solve()
{
  int n, k;
  cin >> n >> k;

  for (int i = 1; i <= n; i++)
    cin >> a[i];

  // 没有孩子时，恰好分配 0 颗糖果有 1 种方案
  dp[0][0] = 1;

  for (int i = 1; i <= n; i++)
  {
    // 对上一层 dp[i-1] 求前缀和
    pre[0] = dp[i - 1][0];

    for (int j = 1; j <= k; j++)
    {
      pre[j] = (pre[j - 1] + dp[i - 1][j]) % MOD;
    }

    // 计算当前孩子对应的所有状态
    for (int j = 0; j <= k; j++)
    {
      if (j <= a[i])
      {
        dp[i][j] = pre[j];
      }
      else
      {
        dp[i][j] = (pre[j] - pre[j - a[i] - 1] + MOD) % MOD;
      }
    }
  }

  cout << dp[n][k] << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
