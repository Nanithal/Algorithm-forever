#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 2e5 + 1;
const int INF = 0x3f3f3f3f;
void solve() {
  bool is_fr[N];
  int n, k, m;
  ll ans = 0;
  cin >> n >> k >> m;
  vector<vector<int>> offer(n + 1);
  vector<vector<int>> accept(n + 1);
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    is_fr[a] = true;
  }
  for (int i = 1; i <= m; i++) {
    int a, b;
    cin >> a >> b;
    if (is_fr[a] && is_fr[b]) {
      ans++;
      continue;
    }
    offer[a].push_back(b);
    accept[b].push_back(a);
  }
  ll maxn1 = 0, maxn2 = 0;
  for (int i = 1; i <= k; i++) {
    if (!is_fr[i]) {
    }
  }
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
