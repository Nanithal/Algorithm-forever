#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

using ll = long long;

int n;
int m;

ll sum = 0;
int maxi = 0;
vector<int> a;

void Solve()
{
    cin >> n >> m;
    a.resize(n);
    for (auto &x : a)
    {
        cin >> x;
        sum += x;
        maxi = max(maxi, x);
    }
    ll t = max((ll)maxi, (sum + m - 1) / m);
    int cc = 1;
    ll cur = 0;
    vector<tuple<int, int, ll, ll>> res;
    for (int i = 0; i < n; i++)
    {
        while (a[i])
        {
            ll curT = min(t - cur, (ll)a[i]);
            res.emplace_back(i, cc, cur, cur + curT);
            cur += curT;
            a[i] -= curT;
            if (cur == t)
            {
                cur = 0;
                cc++;
            }
        }
    }
    cout << res.size();
    for (const auto &[id1, id2, l, r] : res)
    {
        cout << '\n'
             << id1 + 1 << ' ' << id2 << ' ' << l << ' ' << r;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Solve();
}
