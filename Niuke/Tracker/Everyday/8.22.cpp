#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 998244353;
// 考虑到只会单调增加，所以维护最大值
void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ll x = 0;
    bool tne = false; // 目前是否大于MOD
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
            continue; // 乘0不可取，加零无影响
        if (a[i] == 1)
        { // 无论什么情况+1收益大于*1
            x++;
            if (x >= MOD)
                tne = true;
            x %= MOD;
        }
        if (a[i] > 1)
        { // x等于真01时，相加收益大于相乘，其他情况相乘
            if (!tne && (x == 0 || x == 1))
                x += a[i];
            else
                x *= a[i];
            if (x >= MOD)
                tne = true;
            x %= MOD;
        }
    }
    cout << x << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
