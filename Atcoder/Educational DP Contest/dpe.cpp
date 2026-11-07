// https://atcoder.jp/contests/dp/tasks/dp_e

// 01背包+状态维度转换（按照价值进行dp）
// dp[j]定义为恰好获得价值为j所需要的最小重量
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 1e5 + 3;
const int INF = 0x3f3f3f3f;
const ll INFF = 0x3f3f3f3f3f3f3f3f;

// ll dp[105][N];
ll w[N], v[N], dpp[N];

void solve()
{
  int n;
  ll W;
  cin >> n >> W;
  for (int i = 1; i <= N; i++)
  {
    dpp[i] = INFF;
  }
  dpp[0] = 0;
  ll sumV = 0;
  for (int i = 1; i <= n; i++)
  {
    cin >> w[i] >> v[i];
    sumV += v[i];
    for (ll j = sumV; j >= v[i]; j--)
      dpp[j] = min(dpp[j], dpp[j - v[i]] + w[i]);
  }
  ll ans = 0;
  for (int j = 0; j <= sumV; j++)
  {
    if (dpp[j] <= W)
      ans = j;
  }
  cout << ans << endl;
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
