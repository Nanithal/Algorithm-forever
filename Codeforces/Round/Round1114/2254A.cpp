#include <bits/stdc++.h>
using namespace std;
void solve()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c;
    cin >> a >> b >> c;
    int sum = a + b + c;
    int l = max(a, max(b, c));
    int r = min(a, min(b, c));
    int mid = sum - l - r;
    b = sum - a - c;
    int ans = 0;
    while ((l != mid) && (mid != r) && (l != r))
    {
        ans++;
        l -= 1;
        r += 1;
        a = l;
        c = r;
        b = sum - l - r;
        l = max(a, max(b, c));
        r = min(a, min(b, c));
        mid = sum - a - c;
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