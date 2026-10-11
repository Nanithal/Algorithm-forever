#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
const int N = 5e5 + 1;
class block
{
public:
    ll a, b;
} stone[N];
bool com1(block a, block b)
{
    return a.a < b.a;
}
bool com2(block a, block b)
{
    return a.b > b.b;
}
void solve()
{
    ll n, m;
    vector<block> inc, dec;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> stone[i].a >> stone[i].b;
        if (stone[i].a - stone[i].b <= 0)
            inc.push_back(stone[i]);
        else
            dec.push_back(stone[i]);
    }
    sort(inc.begin(), inc.end(), com1);
    bool ok = 1;
    for (const auto &p : inc)
    {
        m -= p.a;
        if (m < 0)
        {
            ok = 0;
            break;
        }
        m += p.b;
    }
    if (ok)
    {
        sort(dec.begin(), dec.end(), com2);
        for (const auto &p : dec)
        {
            m -= p.a;
            if (m < 0)
            {
                ok = 0;
                break;
            }
            m += p.b;
        }
        if (ok)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}