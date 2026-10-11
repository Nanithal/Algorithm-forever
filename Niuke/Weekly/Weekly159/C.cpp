#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int INF = 0x3f3f3f3f;

void solve()
{
    int m, q, b;
    vector<ll> ra;
    ra.push_back(0);
    ll a, sum = 0, p;
    cin >> m >> q >> b;
    for (int i = 1; i <= m; i++)
    {
        cin >> a;
        sum += a;
        ra.push_back(sum);
    }
    for (int i = 1; i <= q; i++)
    {
        cin >> p;
        int l = 1, r = m;
        while (l < r)
        {
            int mid = l + ((r - l) >> 1);
            if (ra[mid] >= p)
                r = mid;
            else
                l = mid + 1;
        }
        if (l & 1)
            cout << b << ' ';
        else
            cout << 1 - b << ' ';
        cout << l << ' ' << p - ra[l - 1] << endl;
    }
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