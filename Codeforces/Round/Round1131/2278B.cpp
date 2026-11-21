
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
  int x, y, z, sum;
  cin >> x >> y >> z;
  sum = x + y + z;
  int maxn = max({x, y, z});
  if (maxn == x)
  {
    for (int i = 1; i <= sum; i++)
      cout << 'P';
    cout << endl;
  }
  else if (maxn == y)
  {
    for (int i = 1; i <= sum; i++)
      cout << 'R';
    cout << endl;
  }
  else 
  {
    for (int i = 1; i <= sum; i++)
      cout << 'S';
    cout << endl;
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
