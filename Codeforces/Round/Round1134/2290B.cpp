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
  string s;
  cin >> n >> s;
  int ans = 0;
  char c = 'R';
  for (int i = 0; i < n; i++)
  {
    if (s[i] != c)
    {
      ans++;
    }
    else
    {
      if (c == 'R')
        c = 'B';
      else
        c = 'R';
    }
  }
  cout << ans << endl;
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
