

#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
bool load[N];
int main()
{
    int n, m, ans;
    cin >> n >> m;
    for (int i = 1; i <= n - 1; i++)
        cin >> load[i];
    for (ans = 1; ans < n;)
    {
        if (!m && load[ans])
            break;
        if (!load[ans])
            ans++;
        else
        {
            m--;
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}