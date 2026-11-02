

// 逆向构造
// #include <bits/stdc++.h>
// using namespace std;

// const int N = 2e5 + 4;
// int a[N], b[N];

// void solve() {
//   int n, can_use = 0;
//   cin >> n;

//   map<int, int> cntA, cntB;
//   vector<pair<int, int>> not_switch;

//   for (int i = 1; i <= n; i++) {
//     cin >> a[i];
//     cntA[a[i]]++;
//   }

//   for (int i = 1; i <= n; i++) {
//     cin >> b[i];
//     cntB[b[i]]++;
//   }

//   // 统计初始可利用元素
//   for (auto [x, c] : cntB) {
//     if (x == 0 || c >= x) {
//       can_use += c;
//     } else {
//       // 解锁数字 x 还需要 x-c 个元素
//       not_switch.push_back({x - c, x});
//     }
//   }

//   // 按解锁所需元素数量升序排列
//   sort(not_switch.begin(), not_switch.end());

//   for (auto [need, x] : not_switch) {
//     int c = cntB[x];

//     if (can_use >= need) {
//       // 可以解锁这一组数字
//       can_use += c;
//     } else {
//       // 无法解锁，只能保留原来的数字
//       if (cntA[x] < c) {
//         cout << "NO\n";
//         return;
//       }
//     }
//   }

//   cout << "YES\n";
// }

// int main() {
//   ios::sync_with_stdio(false);
//   cin.tie(nullptr);

//   int t;
//   cin >> t;

//   while (t--) {
//     solve();
//   }

//   return 0;
// }

// 正向构造思路
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 4;
int a[N], b[N];

void solve() {
  int n;
  cin >> n;

  map<int, int> cntA, cntB;

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cntA[a[i]]++;
  }

  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    cntB[b[i]]++;
  }

  // {need, x}
  vector<pair<long long, int>> not_switch;

  for (auto [x, c] : cntB) {
    not_switch.push_back({1LL * x - c, x});
  }

  sort(not_switch.begin(), not_switch.end());

  int pool = 0;
  int must_keep = 0;

  // 需要重新构造的数字组 {x, c}
  vector<pair<int, int>> build;

  // 第一阶段：确定哪些元素必须保留
  for (auto [need, x] : not_switch) {
    int c = cntB[x];

    if (need <= pool) {
      pool += c;
      build.push_back({x, c});
    } else {
      // 无法重新构造，必须原样保留
      if (cntA[x] < c) {
        cout << "NO\n";
        return;
      }

      must_keep += c;
    }
  }

  // 第二阶段：从 A 出发，正向构造 B
  int can_use = n - must_keep;

  // 按照规划的逆序构造
  for (int i = (int)build.size() - 1; i >= 0; i--) {
    auto [x, c] = build[i];

    // 构造 x 至少需要 x 个位置
    // 最终还需要留下 c 个 x
    if (can_use < max(x, c)) {
      cout << "NO\n";
      return;
    }

    // 本组已有 c 个元素构造完成
    can_use -= c;
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
