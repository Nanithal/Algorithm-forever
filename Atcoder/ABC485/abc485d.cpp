
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 2e5 + 1;
const int INF = 0x3f3f3f3f;
const ll INFF = 0x3f3f3f3f3f3f3f3f;

void solve()
{
  int cnt[3] = {0, 0, 0}, n;
  ll ans = 0;
  cin >> n;
  string s;
  cin >> s;
  s = ' ' + s;
  int l = -1, r = -1;
  for (int i = 1; i <= n; i++)
  {
    cnt[s[i] - 'A']++;
    if (cnt[0] && cnt[1] && cnt[2])
    {
      l = i;
      break;
    }
  }
  memset(cnt, 0, sizeof(cnt));
  for (int i = n; i >= 1; i--)
  {
    cnt[s[i] - 'A']++;
    if (cnt[0] && cnt[1] && cnt[2])
    {
      r = i;
      break;
    }
  }
  if (l == -1)
  {
    cout << 0 << endl;
    return;
  }
  int last[3] = {0, 0, 0};
  r--;
  // 枚举第二个分割点
  for (int i = 1; i <= r; i++)
  {
    last[s[i] - 'A'] = i;
    int t = min({last[0], last[1], last[2]});
    ans += max(0, t - l);
  }
  cout << ans << endl;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  // cin >> t;
  while (t--)
  {
    solve();
  }
  return 0;
}
