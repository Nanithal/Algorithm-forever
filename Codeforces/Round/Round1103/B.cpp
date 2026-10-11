#include <bits/stdc++.h>
using namespace std;
string put;
// char c;
int n, k;
void solve()
{
    cin >> n >> k;
    int num1 = 0, num2 = 0;
    bool ok = 1;
    cin >> put;
    if (n == k)
    {
        for (int i = 0; i < n; i++)
        {
            if (put[i] == '1')
            {
                ok = 0;
                break;
            }
        }
    }
    else
    {
        for (int i = 0; i < k; i++)
        {
            int num = 0;
            int j = i;
            while (j < n)
            {
                if (put[j] == '1')
                    num++;
                j += k;
            }
            if (num & 1)
            {
                ok = 0;
                break;
            }
        }
        for (int i = n - k; i <= k - 1; i++)
        {
            if (put[i] == '1')
            {
                ok = 0;
                break;
            }
        }
    }
    if (ok)
    {
        cout << "YES" << '\n';
    }
    else
    {
        cout << "NO" << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}