
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 5000 + 1;
const int INF = 0x3f3f3f3f;
const ll INFF = 0x3f3f3f3f3f3f3f3f;

ll a[N], f[N][N], g[N][N];
// F[i][j]代表已经处理前i件物品且上一次取走的物品是a[i]，只留下了a[j]物品时目前产生的最小代价
// G[i][j]代表已经处理前i件物品且上一次取走的物品是a[j]，只留下了a[i]物品时目前产生的最小代价

void init()
{
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      f[i][j] = INFF;
      g[i][j] = INFF;
    }
  }
  f[2][1] = g[2][1] = 0;
}

void solve()
{
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  if (n == 1)
  {
    cout << 0 << endl;
    return;
  }
  for (int i = 2; i < n; i++)
  {
    for (int j = 1; j < i; j++)
    {

      // 取走第二件 a[i+1]
      f[i + 1][j] = min(f[i + 1][j], f[i][j] + abs(a[i + 1] - a[i]));

      // 取走第一件 a[j]
      g[i + 1][j] = min(g[i + 1][j], f[i][j] + abs(a[j] - a[i]));
      // 取走第二件 a[i+1]
      f[i + 1][i] = min(f[i + 1][i], g[i][j] + abs(a[i + 1] - a[j]));
      // 取走第一件 a[i]
      g[i + 1][i] = min(g[i + 1][i], g[i][j] + abs(a[i] - a[j]));
    }
  }
  ll ans = INFF;
  for (int i = 1; i < n; i++)
    ans = min(ans, min(f[n][i], g[n][i]) + abs(a[n] - a[i]));
  cout << ans << endl;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  //   cin >> t;
  init();
  while (t--)
  {
    solve();
  }
  return 0;
}
