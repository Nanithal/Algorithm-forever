#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = " " + s;
    int ans = 0;
    for (int i = 1; i <= n;)
    {
        char c = s[i];
        while (s[i] == c && i <= n)
        {
            i++;
        }
        ans++;
    }
    bool ok = 0;
    for (int i = 2; i <= n - 1; i++)
    {
        if (s[i] != s[i - 1] && s[i] != s[i + 1])
        {
            ok = 1;
            break;
        }
    }
    if (ok)
    {
        bool vis = 0;
        for (int i = 2; i <= n - 1; i++)
        {
            if (s[i - 1] == s[i + 1] && s[i] != s[i - 1])
            {
                vis = 1;
                break;
            }
        }
        if (vis)
            ans -= 2;
        else
            ans -= 1;
    }
    cout << ans << endl;
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