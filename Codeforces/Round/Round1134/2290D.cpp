#include <bits/stdc++.h>

#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 2e5 + 1;
const int INF = 0x3f3f3f3f;
const ll INFF = 0x3f3f3f3f3f3f3f3f;

bool com(pair<int, int> a, pair<int, int> b)
{
  return a.first < b.first;
}

void solve()
{
  int n;
  string s;
  cin >> n >> s;
  s = ' ' + s;
  vector<char> sa;
  vector<pair<int, int>> judge;
  int p1 = 1, p2 = n;
  while (p1 < p2)
  {
    if (s[p1] != s[p2])
    {
      int l = min(s[p1], s[p2]) - 'a';
      int r = max(s[p1], s[p2]) - 'a';
      judge.push_back({l, r});
    }
    p1++;
    p2--;
  }
  sort(judge.begin(), judge.end(), com);
  int size = judge.size() - 1;
  int l = 0, r = 0, ans = 0;
  for (int i = 0; i <= size; i++)
  {
    if (judge[i].first > r)
    {
      ans += r - l;
      l = judge[i].first;
      r = judge[i].second;
    }
    else if (judge[i].second > r)
      r = judge[i].second;
  }
  ans += r - l;
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
