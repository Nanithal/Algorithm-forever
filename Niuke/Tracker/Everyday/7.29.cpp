#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
const int N = 2e5 + 1;
const ll modnum = 1e7 + 7;
int n;
ll b;
void solve()
{
    ll ans = 0;
    priority_queue<ll> line;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> b;
        line.push(b);
    }
    while (line.size() >= 2)
    {
        ll temp1 = line.top();
        line.pop();
        ll temp2 = line.top();
        line.pop();
        if (temp1 + temp2 <= 0)
        {
            break;
        }
        ans += temp1 + temp2;
        ans %= modnum;
        line.push(temp1 + temp2);
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