
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;

const int N = 400 + 1;
const ll INFF = 0x3f3f3f3f3f3f3f3f;

ll dp[N][N], a[N], sum[N];
int n;

void solve()
{
  cin >> n;

  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
    sum[i] = sum[i - 1] + a[i];
  }

  for (int len = 2; len <= n; len++)
  {
    for (int l = 1; l + len - 1 <= n; l++)
    {
      int r = l + len - 1;

      dp[l][r] = INFF;

      for (int k = l; k < r; k++)
      {
        dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] + sum[r] - sum[l - 1]);
      }
    }
  }

  cout << dp[1][n] << endl;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  // cin >> t;
  while (t--)
    solve();
  return 0;
}
