// https://www.nowcoder.com/practice/91506d447f3445c999a27d556e530a37?channelPut=tracker2

#include <iostream>
#define endl '\n'
using namespace std;
int m, q, x;
void solve()
{
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        cin >> m >> x;
        int ans = x % m;
        if (!ans)
            ans = m;
        cout << ans << endl;
    }
    return;
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