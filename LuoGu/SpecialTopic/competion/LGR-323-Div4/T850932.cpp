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
  int x, y, z;
  cin >> x >> y >> z;
  if (z - x >= 0)
  {
    cout << "Fine " << z - x << endl;
    return;
  }
  if (z - y >= 0)
  {
    cout << "Quick " << z - y << endl;
    return;
  }
  cout << "Impossible" << endl;
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
