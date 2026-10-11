#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;
int n, k, m;
void solve()
{
    cin >> n >> k >> m;
    bool ok = 0;
    if (k > m) // 因为若k>m，这意味着k个前缀和对m取模结果就至少存在两个数相同（即这两个位置的前缀和相差为m的倍数，那么这两个位置之间就符合要求，此时最短区间就不再是k了）
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (int i = 1; i <= n; i++)
    {
        int temp = i % k;
        if (temp)
            cout << 1 << ' ';
        else
            cout << m - k + 1 << ' ';
    }
    cout << '\n';
    return;
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