// https://www.nowcoder.com/practice/c4986923605c4050986050eb8bfe29ac?channelPut=tracker2
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 2e5 + 1;
const int INF = 0x3f3f3f3f;
void solve()
{
    int n, ans = 0;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n;)
    {
        if (s[i] != '0')
        {
            int l = i;
            while (i < n && s[i] != '0')
                i++;
            ans = max(ans, i - l);
            continue;
        }
        i++;
    }
    for (int i = 0; i < n;)
    {
        if (s[i] != '1')
        {
            int l = i;
            while (i < n && s[i] != '1')
                i++;
            ans = max(ans, i - l);
        }
        i++;
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