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
    vector<int> a(n + 1);
    vector<int> p(n + 1, 0);
    vector<int> q(n + 1, 0);
    vector<int> appear(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        appear[a[i]]++;
        if (appear[a[i]] > 2)
        {
            cout << -1 << endl;
            return;
        }
        if (appear[a[i]] == 1)
            p[i] = a[i];
        else
            q[i] = a[i];
    }
    int cc = 1;
    for (int i = 1; i <= n; i++)
    {
        if (!p[i])
        {
            while (appear[cc])
                cc++;
            p[i] = cc;
            appear[cc]++;
        }
    }
    cc = 1;
    for (int i = 1; i <= n; i++)
    {
        if (!q[i])
        {
            while (appear[cc] == 2)
                cc++;
            q[i] = cc;
            appear[cc]++;
        }
    }
    for (int i = 1; i <= n; i++)
        cout << p[i] << ' ';
    cout << endl;
    for (int i = 1; i <= n; i++)
        cout << q[i] << ' ';
    cout << endl;
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