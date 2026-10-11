#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int INF = 0x3f3f3f3f;

void solve()
{
    int x;
    ll k;
    cin >> x >> k;
    int a[5], num = 0;
    for (int i = 1; i <= 4; i++)
    {
        if ((x & 8) >= 8)
        {
            num++;
            x <<= 1;
            x |= 1;
        }
        else
        {
            x <<= 1;
        }
        x &= 15;
        a[i] = x;
    }
    if (k % 4 == 0)
        cout << a[4] << ' ' << num << endl;
    else
        cout << a[k % 4] << ' ' << num << endl;
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