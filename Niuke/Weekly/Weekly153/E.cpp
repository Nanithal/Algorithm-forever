#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 101;
ll x[N], y[N], n, a, b, c, ans, num1, num2;
inline int judge(int x, int y)
{
    ll num = a * x + b * y + c;
    if (num < 0)
        return 1;
    else if (num > 0)
        return 2;
    return 0;
}
void solve(int l1, int l2)
{
    vector<int> cnt(3, 0);
    a = y[l2] - y[l1];
    b = x[l1] - x[l2];
    c = x[l2] * y[l1] - x[l1] * y[l2];
    for (int i = 1; i <= n; i++)
    {
        if (i == l1 || i == l2)
            continue;
        int save = judge(x[i], y[i]);
        cnt[save]++;
        if (cnt[save] > (n - 2) / 2 && save != 0)
            break;
    }
    if (cnt[1] == cnt[2])
        ans++;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> x[i] >> y[i];
        for (int i = 1; i <= n - 1; i++)
        {
            for (int j = i + 1; j <= n; j++)
                solve(i, j);
        }
    }
    cout << ans;
}