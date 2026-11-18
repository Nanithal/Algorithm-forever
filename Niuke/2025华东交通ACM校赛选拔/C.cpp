
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 2e5 + 1;
const int INF = 0x3f3f3f3f;
const ll INFF = 0x3f3f3f3f3f3f3f3f;

map<char, string> match;

void init()
{
  match['A'] = "la";
  match['B'] = "si";
  match['C'] = "do";
  match['D'] = "re";
  match['E'] = "mi";
  match['F'] = "fa";
  match['G'] = "sol";
}

void solve()
{
  string s;
  cin >> s;
  int size = s.size() - 1;
  bool ok = 0;
  for (int i = 0; i <= size; i++)
  {
    if (s[i] == s[size - i])
    {
      while (s[i] == s[size - i] && i <= size)
        i++;
      i--;
      if (ok)
        cout << endl;
    }
    else
    {
      ok = 1;
      cout << match[s[i]];
    }
  }
  cout << endl;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  init();
  int t = 1;
  //   cin >> t;
  while (t--)
  {
    solve();
  }
  return 0;
}
