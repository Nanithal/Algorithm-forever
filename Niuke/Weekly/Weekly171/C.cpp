
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 2e5 + 1;
const int INF = 0x3f3f3f3f;
const ll INFF = 0x3f3f3f3f3f3f3f3f;

int a[N], sum[N], pre[N];
vector<vector<int>> sa(2 * N);
void solve()
{
  int n, k, sum = 0, ans = 0;
  string s;
  cin >> n >> k;
  cin >> s;
  s = ' ' + s;
  for (int i = 1; i <= n; i++)
  {
    if (s[i] == '0')
      sum += -1;
    else
      sum += 1;
    pre[i] = sum + N;
    sa[sum + N].push_back(i);
  }
  pre[0] = N;
  for (int i = 0; i <= n; i++)
  {
    int base = pre[i];
    if (sa[base + k].size() != 0)
    {
      int size = sa[base + k].size();
      int turn = 1;
      for (auto p : sa[base + k])
      {
        if (p > i)
        {
          ans += size - turn + 1;
          break;
        }
        turn++;
      }
    }

    if (k != 0 && sa[base - k].size() != 0)
    {
      int size = sa[base - k].size();
      int turn = 1;
      for (auto p : sa[base - k])
      {
        if (p > i)
        {
          ans += size - turn + 1;
          break;
        }
        turn++;
      }
    }
  }
  cout << ans << endl;
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
