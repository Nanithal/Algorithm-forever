#include <iostream>
#include <string>
using namespace std;
long long n, x;
void solve()
{
    cin >> n >> x;
    string ans;
    if (x < n * (n + 1) / 2 || x > 13 * n * (n + 1))
    {
        cout << -1 << '\n';
        return;
    }
    for (long long i = 1; i <= n; i++)
        ans += 'a';
    x -= n * (n + 1) / 2;
    while (x)
    {
        for (long long i = n; i >= 1; i--)
        {
            if (!x)
            {
                break;
            }
            if ((x + i - 1) / i <= 25)
            {
                ans[i - 1] += x / i;
                x %= i;
            }
            else
            {
                ans[i - 1] += 25;
                x -= 25 * i;
            }
        }
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}