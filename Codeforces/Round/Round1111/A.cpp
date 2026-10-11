#include <bits/stdc++.h>
using namespace std;
const int N = 101;
int n, a[N], sum;

// 自己尝试的解法
void solve()
{
    sum = 0;
    bool ok = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    if (n == 1)
    {
        cout << "NO\n";
        return;
    }
    if (!sum)
    {
        cout << "YES\n";
        return;
    }
    for (int i = 1; i <= n - 1; i++)
    {
        if (a[i] + a[i + 1] == 0)
            continue;
        if (a[i] > 0)
        {
            if (sum > 0)
            {
                sum -= 4 * a[i];
                a[i] = a[i + 1] = -a[i];
            }
        }
        else
        {
            if (sum < 0)
            {
                sum -= 4 * a[i];
                a[i] = a[i - 1] = -a[i];
            }
        }
        if (!sum)
        {
            ok = 1;
            break;
        }
    }
    if (ok)
        cout << "YES\n";
    else
        cout << "NO\n";
}

// 官方题解
void solve1()
{
    int n, a, sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        sum += a;
    }
    cout << (abs(sum) % 4 == 0 ? "YES\n" : "NO\n");
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve1();
    }
    return 0;
}