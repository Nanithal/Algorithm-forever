#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int INF = 0x3f3f3f3f;

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        if (n > 4)
            n = ceil(sqrt((double)n));
        else if (n > 1)
            n = (n + 1) / 2;
        else
        {
            n -= (m - i + 1);
            break;
        }
    }
    cout << n << endl;
    return;
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