
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
  int x = 1, y = 1, turn = 1, a = 1, b = 1, c;
  for (int i = 1; i <= 14; i++)
  {
    c = a + b;
    a = b;
    b = c;
    if (turn & 1)
      x += c;
    else
      y += c;
    turn++;
  }
  cout << x << ' ' << y << endl;
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
