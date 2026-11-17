#include <bits/stdc++.h>

#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
const ll INFF = 0x3f3f3f3f3f3f3f3f;

ll a[N];

void solve()
{
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  ll ans = 0;
  vector<ll> sum(n + 5, 0);
  for (int i = n; i >= 1; i--)
  {
    a[i] += sum[i + 1] - sum[min(i + k + 1, n + 1)];
    ans += a[i];
    sum[i] = sum[i + 1] + a[i];
  }
  if (ans & 1)
    cout << "Alice\n";
  else
    cout << "Bob\n";
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
