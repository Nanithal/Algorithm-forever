#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 2e5 + 1;
const int INF = 0x3f3f3f3f;
void solve() {
  ll a, b;
  cin >> a >> b;
  if (b - a != 2) {
    cout << "N\n";
    return;
  }
  if (a == 1) {
    cout << "N\n";
    return;
  }
  for (ll j = 2; j * j <= a; j++) {
    if (a % j == 0) {
      cout << "N\n";
      return;
    }
  }
  for (ll j = 2; j * j <= b; j++) {
    if (b % j == 0) {
      cout << "N\n";
      return;
    }
  }
  cout << "Y\n";
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
