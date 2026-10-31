#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 2e5 + 1;
const int INF = 0x3f3f3f3f;
void solve() {
  string s;
  cin >> s;

  int n = s.size();

  vector<vector<int>> dp(n, vector<int>(n, 0));

  for (int len = 2; len <= n; len++) {
    for (int i = 0; i + len <= n; i++) {
      int j = i + len - 1;

      if (s[i] == s[j]) {
        dp[i][j] = dp[i + 1][j - 1];
      } else {
        dp[i][j] = 1 + min({dp[i + 1][j], dp[i][j - 1], dp[i + 1][j - 1]});
      }
    }
  }

  cout << dp[0][n - 1] << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
