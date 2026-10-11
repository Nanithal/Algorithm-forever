#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;
int n, a[N], b[N], num1, num2, num3;

// 自己写的
void solve()
{
    cin >> n;
    bool ok = 1;
    bool vis = 1;
    num1 = num2 = num3 = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        if (b[i] == 0)
            vis = 0;
        if (a[i] == 1 && b[i] == 1)
            num3++;
        if (a[i] == 1 && b[i] == 0)
        {
            ok = 0;
            num1++;
        }
        else if (a[i] == 0 && b[i] == 1)
        {
            ok = 0;
            num2++;
        }
    }
    if (ok)
    {
        cout << 0 << '\n';
        return;
    }
    if (num1 & 1)
    {
        cout << 1 << '\n';
        return;
    }
    else
    {
        if (num1 > 0)
            cout << 2 << '\n';
        else
        {
            if (num3 == 0 || vis)
                cout << -1 << '\n';
            else
                cout << 2 << '\n';
        }
    }
    return;
}
// 官方题解
void solve1()
{
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int &x : a)
        cin >> x;
    for (int &x : b)
        cin >> x;

    if (a == b)
    {
        cout << 0 << '\n';
        return;
    }

    int sum = 0;

    for (int i = 0; i < n; ++i)
    {
        if (a[i] != b[i])
        {
            sum += a[i];
        }
    }

    if (accumulate(a.begin(), a.end(), 0) == 0 || accumulate(b.begin(), b.end(), 0) == n)
    {
        cout << -1 << "\n";
        return;
    }

    if (sum % 2 == 1)
    {
        cout << 1 << '\n';
    }
    else
    {
        cout << 2 << '\n';
    }
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
        solve1();
    }
    return 0;
}