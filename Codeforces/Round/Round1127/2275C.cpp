#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 2e5 + 1;
int a[N];
const int INF = 0x3f3f3f3f;
const ll INFF = 0x3f3f3f3f3f3f3f3f;
void solve() {
  int n;
  cin >> n;
  ll ans = 0;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  map<int, int> sa;
  vector<int> pre;
  pre.push_back(0);
  for (int i = 1; i <= n - 4; i++) {
    int cur = a[i] + a[i + 2] - a[i + 4];
    ans += sa[cur];
    if (i > 2 && pre[i - 2] == cur)
      ans--;
    if (i > 4 && pre[i - 4] == cur)
      ans--;
    sa[cur]++;
    pre.push_back(cur);
  }
  cout << ans << endl;
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
