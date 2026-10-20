#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 2e5 + 1;
const int INF = 0x3f3f3f3f;
void solve() {
  int a, b;
  cin >> a >> b;
  int sma = min(a, b);
  int big = max(a, b);
  if (big - sma != 2) {
    cout << "N\n";
    return;
  }
  if (sma == 1) {
    cout << "N\n";
    return;
  }
  for (int j = 2; j * j <= sma; j++) {
    if (sma % j == 0) {
      cout << "N\n";
      return;
    }
  }
  for (int j = 2; j * j <= big; j++) {
    if (big % j == 0) {
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
