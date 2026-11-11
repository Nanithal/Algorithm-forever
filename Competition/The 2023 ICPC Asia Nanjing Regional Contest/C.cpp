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
  int n, m, k;
  cin >> n >> m >> k;
  bool ok = true;
  int a = 0, b = 0, c = 0, d = 0;
  for (int i = 1; i <= k; i++)
  {
    int x, y, h;
    cin >> x >> y >> h;
    if (x == 1 && y == 1)
      a++;
    else if (x == 1 && y == m)
      b++;
    else if (x == n && y == 1)
      c++;
    else if (x == n && y == m)
      d++;
    else
      ok = false;
  }
  if (!ok)
  {
    cout << -1 << endl;
    return;
  }
  if (n == 1 && m == 1)
  {
    cout << 0 << endl;
    return;
  }
  else if (n == 1)
  {
    cout << abs(a - b) << endl;
    return;
  }
  else if (m == 1)
  {
    cout << abs(a - c) << endl;
    return;
  }
  else
  {
    cout << abs(a - d) + abs(b - c) << endl;
    return;
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
