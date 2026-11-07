#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 2e5 + 1;
ll k, a[N], b[N], c[N], d[N];
bool can_increase[N], cant_down[N];
int n;
const int INF = 0x3f3f3f3f;
const ll INFF = 0x3f3f3f3f3f3f3f3f;

bool check(ll x) {
  ll use = 0;
  for (int i = 1; i <= n; i++) {
    if (d[i] < x) {
      if (can_increase[i])
        use += x - d[i];
      else if (cant_down[i])
        return false;
      else
        use += x - d[i] + 2 * min(b[i] - a[i], c[i] - b[i]) + 2;
    }
    if (use > k)
      return false;
  }
  return true;
}
void solve() {

  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    cin >> a[i] >> b[i] >> c[i];
  ll l = INFF, r;
  for (int i = 1; i <= n; i++) {
    d[i] = a[i] + b[i] + c[i];
    l = min(l, d[i]);
    can_increase[i] = cant_down[i] = false;
    if (a[i] > b[i] || b[i] > c[i] || a[i] > c[i])
      can_increase[i] = true;
    if (a[i] == b[i] && b[i] == c[i])
      cant_down[i] = true;
  }
  r = l + k;
  while (l < r) {
    ll mid = l + ((r - l + 1) / 2);
    if (check(mid)) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  cout << l << endl;
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
