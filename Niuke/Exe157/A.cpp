#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int INF = 0x3f3f3f3f;

void solve()
{
    ll a, b, ans = 0, sum = 0, rest = 0;
    cin >> a >> b;
    vector<ll> p;
    // ll sma = min(a, b);
    // ll big = max(a, b);
    p.push_back(min(a, b));
    p.push_back(max(a, b));
    int idx = 1;
    while (p[idx] >= 2)
    {
        ans += p[idx] / 2;
        p[(idx + 1) % 2] += p[idx] / 2;
        if (p[idx] & 1)
            p[idx] = 1;
        else
            p[idx] = 0;
        idx = (idx + 1) % 2;
    }
    if (ans == 0)
        cout << "Bob\n";
    else if (ans & 1)
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