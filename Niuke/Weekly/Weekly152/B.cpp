#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int INF = 0x3f3f3f3f;

void solve()
{
    int k;
    cin >> k;
    if (k > 21)
    {
        cout << -1 << endl;
        return;
    }
    for (int i = 1; i <= 7; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            if (i & 1)
            {
                if (j & 1 && k)
                {
                    cout << 1;
                    k--;
                }
                else
                    cout << 0;
            }
            else
            {
                if (j & 1)
                    cout << 0;
                else
                {
                    if (k)
                    {
                        cout << 1;
                        k--;
                    }
                    else
                        cout << 0;
                }
            }
        }
        cout << endl;
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