#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
int n, mid;
void solve()
{
    cin >> n;
    mid = (n + 1) / 2;
    if (n & 1)
    {
        for (int i = n; i > 1; i -= 2)
            cout << i << ' ';
        cout << 1 << ' ';
        for (int i = 2; i < n; i += 2)
            cout << i << ' ';
        cout << endl;
        for (int i = n - 1; i > 1; i -= 2)
            cout << i << ' ';
        cout << 1 << ' ';
        for (int i = 3; i <= n; i += 2)
            cout << i << ' ';
        cout << endl;
    }
    else
    {
        for (int i = n; i > 1; i -= 2)
            cout << i << ' ';
        cout << 1 << ' ';
        for (int i = 3; i < n; i += 2)
            cout << i << ' ';
        cout << endl;
        for (int i = n - 1; i > 1; i -= 2)
            cout << i << ' ';
        cout << 1 << ' ';
        for (int i = 2; i <= n; i += 2)
            cout << i << ' ';
        cout << endl;
    }
}
void solve2()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cout << i << ' ';
    cout << endl;
    for (int i = n; i >= 1; i--)
        cout << i << ' ';
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
        solve2();
    }
    return 0;
}