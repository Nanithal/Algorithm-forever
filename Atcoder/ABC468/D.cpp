#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
void solve()
{
    int ans = 0;
    string s;
    cin >> s;
    int size = s.size();
    for (int i = 0; i <= size; i++)
    {
        int num = 0;
        int l = i;
        int r = i;
        while (l >= 0 && r < size)
        {
            if (s[l] != s[r])
            {
                num++;
            }
            if (num <= 1)
            {
                ans++;
            }
            else
                break;
            l--;
            r++;
        }
    }
    for (int i = 0; i <= size - 2; i++)
    {
        int num = 0;
        int l = i;
        int r = i + 1;
        while (l >= 0 && r < size)
        {
            if (s[l] != s[r])
            {
                num++;
            }
            if (num <= 1)
            {
                ans++;
            }
            else
                break;
            l--;
            r++;
        }
    }
    cout << ans << endl;
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