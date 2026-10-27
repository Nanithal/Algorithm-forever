#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class ss {
public:
  int index;
  ll l, r;
};

bool com(ss a, ss b) { return a.l < b.l; }

bool com1(ss a, ss b) { return a.l > b.l; }

void solve() {

  ll n, f, l, r, ans = 0, maxn = 0, maxn_idx;
  cin >> n >> f;

  vector<ss> sa1;
  vector<ss> sa2;
  for (int i = 1; i <= n; i++) {
    cin >> l >> r;
    ans += r - l;
    if (l <= f) {
      sa1.push_back({i, l, r});
      if (r > maxn) {
        maxn = r;
        maxn_idx = i;
      }
    } else
      sa2.push_back({i, l, r});
  }

  sort(sa2.begin(), sa2.end(), com);
  sort(sa1.begin(), sa1.end(), com1);

  if (maxn > f) {
    ll now = maxn;
    for (auto &p : sa2) {
      ans += max(p.l - now, 1ll * 0);
      now = p.r;
    }
    cout << ans << endl;
    for (auto &p : sa1) {
      cout << p.index << ' ';
      if (p.index == maxn_idx) {
        for (auto &q : sa2)
          cout << q.index << ' ';
      }
    }
    cout << endl;
  } else {
    ll now = f;
    for (auto &p : sa2) {
      ans += max(p.l - now, 1ll * 0);
      now = p.r;
    }
    cout << ans << endl;
    for (auto &p : sa2)
      cout << p.index << ' ';
    for (auto &p : sa1)
      cout << p.index << ' ';
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