#include <bits/stdc++.h>

#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 2e5 + 1;
const int INF = 0x3f3f3f3f;
const ll INFF = 0x3f3f3f3f3f3f3f3f;

int a[N], line[N];
void solve()
{
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  int ans = 0;
  sort(a + 1, a + n + 1);
  int max_l = 0, max_r = 0;
  int p1 = 1, p2 = n;
  for (int i = 1; i <= n; i++)
  {
    if (a[i] > max_l)
    {
      line[p1++] = a[i];
      max_l = a[i];
      ans++;
    }
    else
    {
      line[p2--] = a[i];
      if (a[i] > max_r)
      {
        max_r = a[i];
        ans++;
      }
    }
  }
  cout << ans << endl;
  for (int i = 1; i <= n - 1; i++)
    cout << line[i] << ' ';
  cout << line[n] << endl;
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
