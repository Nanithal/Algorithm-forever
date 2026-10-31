// https://codeforces.com/gym/106084/problem/C
// 逆序dp
#include <algorithm>
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 2e5 + 1;
const int INF = 0x3f3f3f3f;
void solve() {
  int n, m;
  cin >> n >> m;

  vector<tuple<int, int, ll>> e(m);
  for (auto &[x, y, v] : e)
    cin >> x >> y >> v;
  vector<ll> dp(n + 1, 0);
  for (int i = m - 1; i >= 0; i--) {
    auto [x, y, v] = e[i];
    swap(dp[x], dp[y]);
    dp[x] += v;
    dp[y] += v;
  }
  cout << *max_element(dp.begin() + 1, dp.end()) << endl;
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
