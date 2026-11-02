#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 2e5 + 1;
const int INF = 0x3f3f3f3f;
const ll INFF = 0x3f3f3f3f3f3f3f3f;
void solve() {
  int n;
  cin >> n;
  vector<vector<ll>> a(n + 1, vector<ll>(3));
  vector<vector<ll>> dp(n + 1, vector<ll>(3));
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 3; j++)
      cin >> a[i][j];
  }
  dp[1][0] = a[1][0];
  dp[1][1] = a[1][1];
  dp[1][2] = a[1][2];
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j < 3; j++) {
      dp[i][j] = max(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]) + a[i][j];
    }
  }
  cout << max({dp[n][0], dp[n][1], dp[n][2]}) << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
