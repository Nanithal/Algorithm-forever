#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n + 1, 0);
    map<ll, vector<ll>> b;
    for (int i = 1; i <= n; i++)
    {
        ll v;
        cin >> v;
        b[v].push_back(i);
    }
    if (b.find(0) == b.end())
    {
        cout << -1 << endl;
        return;
    }
    bool ok = 1;
    ll sum = 0, minn = 0;
    for (auto it = b.begin(); it != b.end(); ++it)
    {
        sum = it->first;
        if (next(it) != b.end())
        {
            auto nxt = next(it);
            ll num = nxt->first;
            num -= sum;
            ll size = it->second.size();
            if (num % size != 0)
            {
                ok = 0;
                break;
            }
            ll goal = num / size;
            if (goal <= minn)
            {
                ok = 0;
                break;
            }
            for (int i = 0; i < it->second.size(); i++)
            {
                a[it->second[i]] = goal;
            }
            minn = goal;
        }
    }
    if (ok)
    {
        for (int i = 1; i <= n; i++)
        {
            if (a[i])
                cout << a[i] << ' ';
            else
                cout << minn + 1 << ' ';
        }
    }
    else
    {
        cout << -1;
    }
    cout << endl;
    return;
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