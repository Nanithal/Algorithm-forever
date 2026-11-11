// https://atcoder.jp/contests/dp/tasks/dp_j
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 300 + 1;
const int INF = 0x3f3f3f3f;
const ll INFF = 0x3f3f3f3f3f3f3f3f;

double dp[N][N][N];
int n;
// dp[i][j][k]定义为当前有i个盘子剩余1个寿司，j个盘子剩余2个寿司，k个盘子剩余3个寿司时，全部吃完所需要消耗的平均操作次数

double dfs(int x, int y, int z)
{
  if (x == 0 && y == 0 && z == 0)
    return 0;
  if (dp[x][y][z] != 0)
    return dp[x][y][z];
  int res = n - x - y - z;
  dp[x][y][z] += 1;
  if (x > 0)
    dp[x][y][z] += 1.0 * x / n * dfs(x - 1, y, z);
  if (y > 0)
    dp[x][y][z] += 1.0 * y / n * dfs(x + 1, y - 1, z);
  if (z > 0)
    dp[x][y][z] += 1.0 * z / n * dfs(x, y + 1, z - 1);
  dp[x][y][z] /= 1.0 - 1.0 * res / n;
  return dp[x][y][z];
}
void solve()
{
  cin >> n;
  int cnt1 = 0, cnt2 = 0, cnt3 = 0;
  for (int i = 1; i <= n; i++)
  {
    int a;
    cin >> a;
    if (a == 1)
      cnt1++;
    else if (a == 2)
      cnt2++;
    else
      cnt3++;
  }
  double ans = dfs(cnt1, cnt2, cnt3);
  cout << fixed << setprecision(15) << ans << endl;
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
