#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;
const int INF = 0x3f3f3f3f;
struct Line {
  int x, y;
  ll v;
};

void solve() {
  int n, m;
  cin >> n >> m;
  vector<Line> lines(m + 1);
  vector<int> judge(n + 1, INF);
  for (int i = 1; i <= m; ++i) {
    cin >> lines[i].x >> lines[i].y >> lines[i].v;
    judge[lines[i].x] = min(judge[lines[i].x], i);
    judge[lines[i].y] = min(judge[lines[i].y], i);
  }

  ll ans1 = 0;
  for (int i = 1; i <= m; ++i) {
    if (judge[lines[i].x] != i)
      continue;
    int curCol = lines[i].x;
	ll temp = 0;
    curCol = (curCol == lines[i].x ? lines[i].y : lines[i].x);
    temp += lines[i].v;
    for (int j = i + 1; j <= m; j++) {
      if (lines[j].x != curCol && lines[j].y != curCol)
        continue;
      curCol = (curCol == lines[j].x ? lines[j].y : lines[j].x);
      temp += lines[j].v;
    }
	ans1 =max (ans1,temp);
  }

  ll ans2 = 0;
  for (int i = 1; i <= m; ++i) {
    if (judge[lines[i].y] != i)
      continue;
    int curCol = lines[i].y;
	ll temp = 0;
    curCol = (curCol == lines[i].x ? lines[i].y : lines[i].x);
    temp += lines[i].v;
    for (int j = i + 1; j <= m; j++) {
      if (lines[j].x != curCol && lines[j].y != curCol)
        continue;
      curCol = (curCol == lines[j].x ? lines[j].y : lines[j].x);
      temp += lines[j].v;
    }
	ans2 =max (ans2,temp);
  }

  cout << max(ans1, ans2) << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int _ = 1;
  cin >> _;
  while (_--)
    solve();

  return 0;
}
