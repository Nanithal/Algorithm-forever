#include <bits/stdc++.h>
using namespace std;
void solve()
{
    long long n, k;
    cin >> n >> k;
    long long a = 0, b = 0, num = 0;
    while (a <= n)
    {
        for (int i = 1; i <= k; i++)
        {
            a += pow(2, b);
            if (a <= n)
            {
                num++;
            }
            else
                break;
        }
        b++;
    }
    cout << num << '\n';
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
    return 0;
}