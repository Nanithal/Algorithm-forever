#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 2e5 + 1;
const int INF = 0x3f3f3f3f;
void solve() {
  ll x, d;
  cin >> x >> d;
  if (x * 2 <= d)
    cout << "double it" << endl;
  else
    cout << "take it" << endl;
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
