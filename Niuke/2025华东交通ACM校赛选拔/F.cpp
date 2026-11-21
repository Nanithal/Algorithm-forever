
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 2e7;
const int INF = 0x3f3f3f3f;
const ll INFF = 0x3f3f3f3f3f3f3f3f;
vector<ll> primes;
vector<bool> isnot_prime(N + 1);
void init()
{
  for (int i = 2; i <= N; i++)
  {
    if (!isnot_prime[i])
      primes.push_back(i);
    for (ll p : primes)
    {
      if (i * p > N)
        break;
      isnot_prime[i * p] = true;
      if (i % p == 0)
        break;
    }
  }
}

void solve()
{
  int size = primes.size();
  int x, n;
  cin >> n >> x;
  if (x > size)
  {
    cout << "Smotth\n";
    return;
  }
  if (primes[x - 1] <= n || primes[x - 1] >= 2 * n)
  {
    cout << "Smooth\n";
    return;
  }
  cout << "Rough ";
  int ans = 1;
  for (int i = x - 2; i >= 0; i--)
  {
    if (primes[i] > n && primes[i] < 2 * n)
      ans++;
    else
      break;
  }
  cout << ans << endl;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  init();
  int t = 1;
  cin >> t;
  while (t--)
  {
    solve();
  }
  return 0;
}
