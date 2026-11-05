// https://atcoder.jp/contests/dp/tasks/dp_e
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 1e5 + 3;
const int INF = 0x3f3f3f3f;
const ll INFF = 0x3f3f3f3f3f3f3f3f;
ll dp[105][N];
ll w[N], v[N], dpp[N];
void solve() {
  int n;
  ll W;
  cin >> n >> W;
  for (int i = 1; i <= n; i++)
    cin >> w[i] >> v[i];
  for (int i = 1; i <= n; i++) {
    for (ll j = 0; j <= W; j++) {
      dp[i][j] = dp[i - 1][j];
      if (j >= w[i])
        dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
    }
  }
  cout << dp[n][W] << endl;
}
void solve1() {
  int n;
  ll W;
  cin >> n >> W;
  for (int i = 1; i <= n; i++)
    cin >> w[i] >> v[i];
  for (int i = 1; i <= n; i++) {
    for (ll j = W; j >= w[i]; j--)
      dpp[j] = max(dpp[j], dpp[j - w[i]] + v[i]);
  }
  cout << dpp[W] << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve1();
  }
  return 0;
}
