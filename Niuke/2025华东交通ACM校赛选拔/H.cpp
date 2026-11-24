
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 2e5 + 1;
const int INF = 0x3f3f3f3f;
const ll INFF = 0x3f3f3f3f3f3f3f3f;

ll a[N], pre[N];
int n, midd;
ll k;

bool check(ll x)
{
  ll base = x - a[midd];
  ll num = base;
  for (int i = midd + 1; i <= n; i++)
  {
    num += max(base - pre[i], 0ll);
  }
  if (num <= k)
    return true;
  else
    return false;
}

void solve()
{

  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  sort(a + 1, a + n + 1);
  midd = (n + 1) / 2;
  for (int i = midd + 1; i <= n; i++)
    pre[i] = a[i] - a[midd];
  ll l = a[midd], r = k + l;
  while (l < r)
  {
    ll mid = l + ((r - l + 1) >> 1);
    if (check(mid))
      l = mid;
    else
      r = mid - 1;
  }
  cout << l << endl;
}


void solve1()
{
    int n;
    ll k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    sort(a + 1, a + n + 1);

    int m = (n + 1) / 2;
    ll ans = a[m];
    ll cnt = 1;

    for (int i = m + 1; i <= n; i++)
    {
        ll cost = (a[i] - ans) * cnt;

        if (cost > k)
        {
            ans += k / cnt;
            k = 0;
            break;
        }

        k -= cost;
        ans = a[i];
        cnt++;
    }

    if (k > 0)
        ans += k / cnt;

    cout << ans << endl;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  //   cin >> t
  while (t--)
  {
    solve1();
  }
  return 0;
}
