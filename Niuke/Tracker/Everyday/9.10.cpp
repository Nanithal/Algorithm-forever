// https://www.nowcoder.com/practice/c1e6857fa1d343a4a3ce7446e3d39539?channelPut=tracker2
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 1e3 + 1;
const int INF = 0x3f3f3f3f;
int a[N][N];
void solve()
{
    int n, m, k, ans = 0;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        s = ' ' + s;
        for (int j = 1; j <= m; j++)
            a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + s[j] - '0';
    }
    int row = n - k + 1;
    int cow = m - k + 1;
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= cow; j++)
            ans += ((a[i + k - 1][j + k - 1] + a[i - 1][j - 1] - a[i - 1][j + k - 1] - a[i + k - 1][j - 1] > 0) ? 1 : 0);
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