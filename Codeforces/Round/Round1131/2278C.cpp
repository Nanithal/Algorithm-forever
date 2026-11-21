
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 2e5 + 1;
const int INF = 0x3f3f3f3f;
const ll INFF = 0x3f3f3f3f3f3f3f3f;

int a[N], n, sum[N];

void solve()
{
  cin >> n;
  bool ok = false;
  cin >> a[1];
  sum[1] = a[1];
  for (int i = 2; i < n; i++)
  {
    cin >> a[i];
    if (!ok && a[i] >= 2)
      ok = true;
    sum[i] = sum[i - 1] + a[i];
  }
  cin >> a[n];
  sum[n] = sum[n - 1] + a[n];
  if (sum[n] == n)
  {
    cout << -1 << endl;
    return;
  }
  int ans;
  if (ok)
  {
    ans = sum[n] - 1;
    cout << ans << endl;
  }
  else
  {
    ans = sum[n] - n + 1;
    cout << ans << endl;
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--)
  {
    solve();
  }
  return 0;
}
