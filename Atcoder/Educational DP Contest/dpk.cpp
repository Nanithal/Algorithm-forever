#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int N = 1e5 + 1;
int a[101];
bool dp[N]; // dp[i] 表示剩余 i 个石子时，当前玩家是否必胜

void solve()
{
  int n, k;
  cin >> n >> k;

  for (int i = 1; i <= n; i++)
    cin >> a[i];

  for (int i = 1; i <= k; i++)
  {
    bool ok = false;

    for (int j = 1; j <= n; j++)
    {
      if (a[j] <= i && !dp[i - a[j]])
      {
        ok = true;
        break;
      }
    }

    dp[i] = ok;
  }

  if (dp[k])
    cout << "First" << endl;
  else
    cout << "Second" << endl;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  // cin >> t;
  while (t--)
    solve();

  return 0;
}