#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve()
{
  int n;
  cin >> n;
  map<string, int> mp;
  for (int i = 0; i < n; ++i)
  {
    string s;
    cin >> s;
    ++mp[s];
  }
  for (auto [s, v] : mp)
  {
    if (v > n / 2)
    {
      cout << s << endl;
      return;
    }
  }
  cout << "uh-oh" << endl;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int _ = 1;
  // cin >> _;
  while (_--)
    solve();

  return 0;
}
