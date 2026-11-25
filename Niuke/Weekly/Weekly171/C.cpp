
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 2e5 + 1;
const int INF = 0x3f3f3f3f;
const ll INFF = 0x3f3f3f3f3f3f3f3f;

ll cnt[4 * N + 5];

void solve()
{
  int n, k;
  ll ans = 0;
  cin >> n >> k;
  string s;
  cin >> s;
  int pre = 2 * N;
  cnt[pre] = 1;
  for (int i = 0; i < n; i++)
  {
    if (s[i] == '1')
      pre += 1;
    else
      pre += -1;
    ans += cnt[pre + k];
    if (k != 0)
      ans += cnt[pre - k];
    cnt[pre]++;
  }
  cout << ans << endl;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;

  while (t--)
  {
    solve();
  }

  return 0;
}
