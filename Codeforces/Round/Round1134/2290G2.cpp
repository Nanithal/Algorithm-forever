// https://codeforces.com/problemset/problem/2290/G1
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 1e6 + 5;
const int INF = 0x3f3f3f3f;
const ll INFF = 0x3f3f3f3f3f3f3f3f;

int n, pos;
ll k, h[N], need[N];

bool check(ll x)
{
  for (int i = 1; i <= n; i++)
    need[i] = h[i];

  // 从最高点开始，顺时针扫描
  int cur = pos;

  for (int i = 1; i < n; i++)
  {
    int nxt = cur + 1;
    if (nxt > n)
      nxt = 1;
    need[nxt] = max(need[nxt], need[cur] - x);
    cur = nxt;
  }
  // 从最高点开始，逆时针扫描
  cur = pos;

  for (int i = 1; i < n; i++)
  {
    int pre = cur - 1;

    if (pre == 0)
      pre = n;

    need[pre] = max(need[pre], need[cur] - x);

    cur = pre;
  }

  // 计算所需泥土
  ll cost = 0;

  for (int i = 1; i <= n; i++)
  {
    cost += need[i] - h[i];

    if (cost > k)
      return false;
  }
  return true;
}

void solve()
{
  cin >> n >> k;
  pos = 1;
  for (int i = 1; i <= n; i++)
  {
    cin >> h[i];
    if (h[i] > h[pos])
      pos = i;
  }
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
