
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
  string s;
  cin >> s;
  int size = s.size();
  int num = 0;
  vector<int> a(26), b(26);
  for (int i = 0; i < size; i++)
  {
    int idx;
    if (isupper(s[i]))
    {
      idx = s[i] - 'A';
      a[idx]++;
    }
    else
    {
      idx = s[i] - 'a';
      b[idx]++;
    }
    if (a[idx] + b[idx] == 1)
      num++;
  }
  if (num == 5)
    cout << "Yes\n";
  else
    cout << "No\n";
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
