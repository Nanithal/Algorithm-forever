#include <bits/stdc++.h>
using namespace std;
int n;
string a, b;
void solve()
{
    vector<int> l1;
    vector<int> l2;
    int l1odd = 0, l1even = 0, l2odd = 0, l2even = 0;
    cin >> n;
    cin >> a >> b;
    a = " " + a;
    b = " " + b;
    if (a == b)
    {
        cout << "YES\n";
        return;
    }
    if (a != b && n < 3)
    {
        cout << "NO\n";
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == '1' && b[i] == '0')
            l1.push_back(i);
        else if (a[i] == '0' && b[i] == '1')
            l2.push_back(i);
    }
    for (auto &p : l1)
    {
        if (p & 1)
            l1odd++;
        else
            l1even++;
    }
    for (auto &p : l2)
    {
        if (p & 1)
            l2odd++;
        else
            l2even++;
    }
    if (l1odd == l2odd && l1even == l2even)
        cout << "YES\n";
    else
        cout << "NO\n";
    return;
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