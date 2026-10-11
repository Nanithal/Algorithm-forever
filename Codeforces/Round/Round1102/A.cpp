#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
const int N = 101;
int b[N];
int n;
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    if (n == 2)
    {
        cout << max(b[1], b[2]) << ' ' << min(b[1], b[2]) << '\n';
        return;
    }
    else
    {
        sort(b + 1, b + n + 1);
        for (int i = 1; i <= n - 2; i++)
        {
            if (b[i] != b[i + 2] % b[i + 1])
            {
                cout << -1 << '\n';
                return;
            }
        }
        cout << b[n] << ' ' << b[n - 1] << '\n';
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