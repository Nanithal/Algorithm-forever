// https://codeforces.com/problemset/problem/2290/G1
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
const ll INFF = 0x3f3f3f3f3f3f3f3f;

int n;
ll k, h[N];

bool check(ll x)
{
  ll cost = 0;
  for (int i = 1; i <= n; i++)
  {
    ll need = h[i];

    for (int j = 1; j <= n; j++)
    {
      int dis = abs(i - j);
      dis = min(dis, n - dis);

      need = max(need, h[j] - x * dis);
    }
    cost += need - h[i];
    if (cost > k)
      return false;
  }
  return true;
}

void solve()
{
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    cin >> h[i];
  h[n + 1] = h[1];
  ll l = 0, r = 0;
  for (int i = 1; i <= n; i++)
    r = max(r, abs(h[i] - h[i + 1]));
  while (l < r)
  {
    ll mid = l + ((r - l) >> 1);
    if (check(mid))
      r = mid;
    else
      l = mid + 1;
  }
  cout << l << endl;
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
