#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 2e5 + 1;
const int INF = 0x3f3f3f3f;
void solve() {
  ll a, b, ha, hb;
  cin >> a >> b >> ha >> hb;
  ll num1 = (ha + b - 1) / b;
  ll num2 = (hb + a - 1) / a;
  if (num1 >= num2 + 4)
    cout << "YES\n";
  else
    cout << "NO\n";
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
