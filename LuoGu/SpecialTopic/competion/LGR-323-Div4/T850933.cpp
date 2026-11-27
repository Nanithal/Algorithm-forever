
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
  int n;
  cin >> n;
  string a;
  for (int i = 1; i <= n; i++)
    a.push_back('.');
  int up = (n + 1) / 2;
  for (int i = 1; i <= up; i++)
  {
    for (int j = 1; j < i; j++)
      cout << '.';
    for (int j = i; j <= n - i + 1; j++)
      cout << '*';
    for (int j = n - i + 2; j <= n; j++)
      cout << '.';
    cout << endl;
  }
  for (int i = up + 1; i <= n; i++)
    cout << a << endl;
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
