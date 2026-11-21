
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
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    sort(a + 1, a + n + 1);

    ll cost = 0;

    for (int i = 1; i < n; i++)
    {
        ll dis = a[i + 1] - a[i];
        cost += dis * min(i, n - i);
    }

    ll cnt = a[n] - a[1];

    cout << cost << " " << cnt << endl;
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
