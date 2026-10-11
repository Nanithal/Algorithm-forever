#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m;
  cin >> n >> m;
  int res = m % n;
  int hd = m / n;
  for (int i = 1; i <= n; i++) {
    cout << hd + ((res >= i) ? 1 : 0) << endl;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}