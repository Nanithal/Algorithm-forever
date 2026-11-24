
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 1e5 + 1;
const int INF = 0x3f3f3f3f;
const ll INFF = 0x3f3f3f3f3f3f3f3f;

ll k, m, n;
ll a[N], sum[N], b[N];
void solve()
{
  cin >> k >> m >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
    sum[i] = sum[i - 1] + a[i];
  }
  for (int i = 1; i <= n; i++)
    cin >> b[i];
  ll l = 0, r = k * m;
  for (int i = 1; i <= n; i++)
  {
    ll sma, big;
    if (b[i] == 0)
    {
      sma = 0;
      big = k + i - 1 - sum[i];
    }
    else
    {
      sma = b[i] * (k + i) - sum[i];
      big = sma + k + i - 1;
    }
    if (sma > r || big < l)
    {
      cout << 0 << endl;
      return;
    }
    l = max(l, sma);
    r = min(r, big);
  }
  cout << r - l + 1 << endl;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  //   cin >> t;
  while (t--)
  {
    solve();
  }
  return 0;
}
