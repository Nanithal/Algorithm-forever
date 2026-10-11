// https://www.nowcoder.com/practice/e364bac751204aa0b2d27389ca8e3c94?channelPut=tracker2

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int INF = 0x3f3f3f3f;
const int N = 1e5 + 1;
int a[N], b[N];
void solve()
{

    ll ans, temp = 0;
    int n;
    cin >> n >> ans;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
        temp += min(a[i], b[i]);
    ans = min(ans, temp);
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