#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 2e5 + 1;
const int INF = 0x3f3f3f3f;

struct loca {
  int x;
  int y;
};
void solve() {
  loca loc[5];
  for (int i = 1; i <= 4; i++)
    cin >> loc[i].x >> loc[i].y;

  if (((loc[3].x >= loc[1].x && loc[3].x <= loc[2].x) &&
       (loc[3].y >= loc[1].y && loc[3].y <= loc[2].y)) ||
      ((loc[4].x >= loc[1].x && loc[4].x <= loc[2].x) &&
       (loc[4].y >= loc[1].y && loc[4].y <= loc[2].y))) {
    cout << "STOP\n";
    return;
  }
  if (loc[3].x == loc[4].x || loc[3].y == loc[4].y) {
    cout << "OK\n";
    return;
  }
  loca hig = (loc[3].y > loc[4].y) ? loc[3] : loc[4];
  loca low = (loc[3].y < loc[4].y) ? loc[3] : loc[4];
  if (hig.y > loc[4].y) {
    if (((hig.y - low.y) * (hig.x - loc[1].x) <
         (hig.y - loc[1].y) * (hig.x - low.x)) ||
        ((hig.y - low.y) * (hig.x - loc[2].x) <
         (hig.y - loc[2].y) * (hig.x - low.x)))
  }
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
