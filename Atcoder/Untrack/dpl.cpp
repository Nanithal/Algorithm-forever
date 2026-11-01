// https://atcoder.jp/contests/dp/tasks/dp_l
// 区间dp

// 假设dp[i][j]代表剩下下标为i-j的数时，先手（一开始决定好的先手）所能取得的最大分数差
// 此时若已经取走了偶数个，则需要最大化
// 反之，需要最小化
#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 2e5 + 1;
const int INF = 0x3f3f3f3f;
void solve() {
  int n;
  cin >> n;
  vector<ll> a(n + 2);
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  vector<vector<ll>> dp(n + 2, vector<ll>(n + 2, 0));
  for (int len = 1; len <= n; len++) {
    for (int i = 1; i + len - 1 <= n; i++) {
      int j = i + len - 1;
      if ((n - len) & 1)
        dp[i][j] = min(dp[i + 1][j] - a[i], dp[i][j - 1] - a[j]);
      else
        dp[i][j] = max(dp[i + 1][j] + a[i], dp[i][j - 1] + a[j]);
    }
  }
  cout << dp[1][n] << endl;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  //   cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
