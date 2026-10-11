#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 2e5 + 1;
const int INF = 0x3f3f3f3f;
void solve()
{
    int n, a;
    cin >> n;
    priority_queue<int> sa;
    for (int i = 1; i <= 2; i++)
    {
        cin >> a;
        sa.push(a);
    }
    for (int i = 3; i <= n; i++)
    {
        cin >> a;
        sa.push(a);
        int temp1 = sa.top();
        sa.pop();
        int temp2 = sa.top();
        sa.pop();
        cout << sa.top() << endl;
        sa.push(temp1);
        sa.push(temp2);
    }
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