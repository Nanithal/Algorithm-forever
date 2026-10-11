#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
const int N = 101;
int a[N];
int num[N];
void solve()
{
    int n, maxn = -1, max_loc, sum = 0;
    priority_queue<int, vector<int>, greater<int>> sa;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] == -1)
        {
            sa.push(i);
            continue;
        }
        num[a[i]]++;
        sum += a[i];
        if (maxn < a[i])
        {
            maxn = a[i];
            max_loc = i;
        }
    }
    if (!sa.size())
    {
        cout << max_loc << endl;
        return;
    }
    int rest = n - sum;
    if (rest <= maxn)
    {
        cout << max_loc << endl;
    }
    else if ((maxn - 1) * (int)sa.size() >= rest)
    {
        if (num[maxn] == 1)
            sa.push(max_loc);
        while (sa.size())
        {
            cout << sa.top() << ' ';
            sa.pop();
        }
    }
    else
    {
        while (sa.size())
        {
            cout << sa.top() << ' ';
            sa.pop();
        }
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