#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int INF = 0x3f3f3f3f;

void solve()
{
    int n;
    cin >> n;
    stack<char> ans;
    for (int i = 1; i <= n; i++)
    {
        char c;
        cin >> c;
        if (!ans.empty())
        {
            if (isupper(ans.top()) && ans.top() + c - 'A' - 'A' == 25 && ans.top() > c)
                ans.pop();
            else if (!isupper(ans.top()) && ans.top() + c - 'a' - 'a' == 25 && ans.top() < c)
                ans.pop();
            else
                ans.push(c);
        }
        else
            ans.push(c);
    }
    cout << ans.size() << endl;
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