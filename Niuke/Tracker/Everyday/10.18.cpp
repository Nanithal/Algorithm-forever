#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 2e5 + 1;
const int INF = 0x3f3f3f3f;
void solve() {
  ll n, k;
  cin >> n >> k;
  ll ans = 0, up = min(n, k);
  ans += max((ll)0, n - k) * k;
  for (ll l = 1, r; l <= up; l = r + 1) {
    ll res = k / l;
    r = min(up, k / res);
    ll sa = k % l;
    ll reg = r - l + 1;
    ans += sa * reg - reg * res * (reg - 1) / 2;
  }
  cout << ans << endl;
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
