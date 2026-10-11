#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int D, M, ans;
string a;
void solve()
{
    ans = 0;
    cin >> M >> D;
    cin >> a;
    for (int i = 0; i < M; i++)
    {
        if (a[i] == '.')
        {
            bool ok = 1;
            int l = i - 1;
            int r = i + 1;
            while (l >= 0 && i - l <= D)
            {
                if (a[l] == 'G')
                {
                    ok = 0;
                    break;
                }
                l--;
            }
            while (r < M && r - i <= D)
            {
                if (a[r] == 'G')
                {
                    ok = 0;
                    break;
                }
                r++;
            }
            if (ok)
                ans++;
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