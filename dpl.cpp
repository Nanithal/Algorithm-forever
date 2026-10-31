// https://atcoder.jp/contests/dp/tasks/dp_l
#include <bits/stdc++.h>
#define endl '\n'
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
  for (int len = 2; len <= n; len++) {
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
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  //   cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
