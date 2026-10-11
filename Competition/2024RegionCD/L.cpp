#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 2e5 + 1;
const int INF = 0x3f3f3f3f;
void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  cout << 100 << endl;
  for (int i = 1; i <= 50; i++) {
    cout << a << ' ';
  }
  for (int i = 51; i <= 95; i++) {
    cout << b << ' ';
  }
  for (int i = 96; i <= 99; i++) {
    cout << c << " " ;
  }
  cout << c + 1 << endl;
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
