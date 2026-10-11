#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 1e5 + 10;
const ll MOD = 998244353;
int num[N], a[N];
const int INF = 0x3f3f3f3f;

ll fast_pow(int n)
{
    ll res = 1;
    ll temp = 2;
    while (n)
    {
        if (n & 1)
        {
            res *= temp;
            res %= MOD;
        }
        temp *= temp;
        temp %= MOD;
        n >>= 1;
    }
    return res;
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int b;
        cin >> b;
        num[b]++;
    }
    for (int i = 1; i <= num[0]; i++)
        a[i] = 0;
    int num1 = num[0], num2 = 0, opt = 1;
    for (int i = num[0] + 1; i <= n; i++)
    {
        if (opt & 1)
        {
            if (num[num1])
            {
                a[i] = num1;
                num2++;
            }
            else
                i--;
        }
        else
        {
            if (num[num2])
            {
                a[i] = num2;
                num1++;
            }
            else
                i--;
        }
        opt++;
    }
    // for (int i = 1; i <= n; i++)
    //     cout << a[i] << ' ';
    // cout << endl;
    int aa = 0, bb = 0, cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == aa && a[i] == bb)
        {
            cnt++;
            aa++;
        }
        else if (a[i] == aa)
            bb++;
        else
            aa++;
    }
    cout << fast_pow(cnt) << endl;
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