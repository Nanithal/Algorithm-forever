
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 2e5 + 1;
const int INF = 0x3f3f3f3f;
const ll INFF = 0x3f3f3f3f3f3f3f3f;

int a[N], b[N], n;

void solve()
{
  cin >> n;
  vector<bool> vis(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> b[i];
  for (int i = 1; i <= n; i++)
  {
    int pos = n + 1 - i + b[i];
    if (pos < 1 || pos > n || vis[pos])
    {
      cout << -1 << endl;
      return;
    }
    a[pos] = i;
    vis[pos] = true;
  }
  for (int i = 1; i <= n; i++)
    cout << a[i] << ' ';
  cout << endl;
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
