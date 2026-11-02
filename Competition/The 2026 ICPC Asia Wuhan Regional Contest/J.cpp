
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 4;
int a[N], b[N];

void solve() {
  int n, can_use = 0;
  cin >> n;

  map<int, int> cntA, cntB;
  vector<pair<int, int>> not_switch;

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cntA[a[i]]++;
  }

  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    cntB[b[i]]++;
  }

  // 统计初始可利用元素
  for (auto [x, c] : cntB) {
    if (x == 0 || c >= x) {
      can_use += c;
    } else {
      // 解锁数字 x 还需要 x-c 个元素
      not_switch.push_back({x - c, x});
    }
  }

  // 按解锁所需元素数量升序排列
  sort(not_switch.begin(), not_switch.end());

  for (auto [need, x] : not_switch) {
    int c = cntB[x];

    if (can_use >= need) {
      // 可以解锁这一组数字
      can_use += c;
    } else {
      // 无法解锁，只能保留原来的数字
      if (cntA[x] < c) {
        cout << "NO\n";
        return;
      }
    }
  }

  cout << "YES\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
