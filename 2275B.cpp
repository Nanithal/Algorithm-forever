#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 2e5 + 1;
const int INF = 0x3f3f3f3f;
const ll INFF = 0x3f3f3f3f3f3f3f3f;
void solve() {
  int n, num;
  string s;
  cin >> n >> s;
  num = n;
  vector<bool> printed(n + 1, false);
  stack<int> sa;
  s = ' ' + s;
  for (int i = 1; i <= n; i++) {
    char c = s[i];
    switch (c) {
    case '1':
      sa.push(i);
      break;
    case '2':
      if (!sa.empty()) {
        if (!printed[sa.top()])
          num--;
        printed[sa.top()] = true;
        sa.pop();
      } else {
        if (!printed[i])
          num--;
        printed[i] = true;
      }
      break;
    case '3':
      if (!printed[i])
        num--;
      printed[i] = true;
    }
  }
  cout << num << endl;
  if (num) {
    for (int i = 1; i <= n; i++) {
      if (!printed[i])
        cout << i << ' ';
    }
  }
  cout << endl;
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
