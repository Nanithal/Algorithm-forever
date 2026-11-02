// https://atcoder.jp/contests/dp/tasks/dp_b

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 2e5 + 1;
const int INF = 0x3f3f3f3f;
const ll INFF = 0x3f3f3f3f3f3f3f3f;
void solve() {
  int n, k;
  cin >> n >> k;
  vector<ll> a(n + 1);
  a[0] = INFF;
  vector<ll> dp(n + 1, INFF);
  dp[1] = 0;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 2; i <= n; i++) {
    for (int j = i - 1; j >= 1; j--) {
      if (i - j > k)
        break;
      dp[i] = min(dp[j] + abs(a[i] - a[j]), dp[i]);
    }
  }
  cout << dp[n];
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
