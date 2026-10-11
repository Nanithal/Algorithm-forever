#include <bits/stdc++.h>
using namespace std;
int n, m, k, num;
void solve()
{
    cin >> n >> m >> k;
    // if (n < 2 || m < 2)
    // {
    //     cout << "No\n";
    //     return;
    // }

    // n=1或者m=1的时候，也可能满足任意2X2区域均既有0和1
    num = (n / 2) * (m / 2);
    if (k < num || k > n * m - num)
    {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    if (k <= (m + 1) / 2 * n + num)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (i % 2 == 0 && j % 2 == 0)
                    cout << 1;
                else if (j % 2 == 1 && k > num)
                {
                    cout << 1;
                    k--;
                }
                else
                    cout << 0;
            }
            cout << endl;
        }
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (i % 2 == 0 && j % 2 == 0)
                    cout << 0;
                else if (k > 0)
                {
                    cout << 1;
                    k--;
                }
                else
                    cout << 0;
            }
            cout << endl;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
