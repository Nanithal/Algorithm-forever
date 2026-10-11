#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 1;
int a[N], sa[N];
ll n, k, ans = INF;
void solve()
{

    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int l = 1, r = 1;
    ll cnt = 0;
    while (l <= r && r <= n + 1)
    {
        if (cnt < k)
        {
            cnt += sa[a[r]];
            sa[a[r]]++;
            r++;
        }
        else
        {
            ans = min(ans, (ll)r - l);
            sa[a[l]]--;
            cnt -= sa[a[l]];
            l++;
        }
    }
    if (ans != INF)
        cout << ans << endl;
    else
        cout << -1 << endl;
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