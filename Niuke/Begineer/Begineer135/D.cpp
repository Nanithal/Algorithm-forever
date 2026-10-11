#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;
int n, a;
void solve()
{
    int num = 0;
    cin >> n;
    stack<int> st;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        a %= 9;
        if (!st.empty() && (st.top() + a) % 9 == 0)
        {
            st.pop();
            num++;
        }
        else
            st.push(a);
    }
    if (num & 1)
        cout << "Yes" << '\n';
    else
        cout << "No" << '\n';
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