
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
  int n, size, div;
  string s;
  cin >> n >> s;
  size = s.size();
  div = 2 * n;
  s = ' ' + s;
  for (int i = 1; i <= n; i++)
  {
    int base = i;
    int res = (size - base) / div;
    base += div * res;
    if (base + div + 1 - 2 * i <= size)
      base += div + 1 - 2 * i;
    cout << s[base];
  }
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
