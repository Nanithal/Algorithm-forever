#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
const int N = 11;
int p[N], q[N], n;
ll a, b;
ll calA(int x)
{
    int temp = 1;
    for (int i = 2; i <= x; i++)
        temp *= i;
    return temp;
}
void solve()
{
    vector<bool> vis1(n + 1, 0);
    vector<bool> vis2(n + 1, 0);
    ll ans = 0;
    a = b = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    for (int i = 1; i <= n; i++)
        cin >> q[i];
    // for (int i = 1; i <= n; i++)
    // {
    //     a *= 10;
    //     if (p[i] == 10)
    //         a *= 10;
    //     a += p[i];
    //     b *= 10;
    //     if (q[i] == 10)
    //         b *= 10;
    //     b += q[i];
    // }
    int num = 1;
    while (p[num] == q[num] && num < n)
    {
        vis1[p[num]] = vis2[p[num]] = 1;
        num++;
    }
    // 直接判断第一位不同的数位来判断是否o的字典序大于q
    if (p[num] > q[num])
    {
        cout << 0 << endl;
        return;
    }
    int temp = 0;
    for (int i = p[num] + 1; i < q[num]; i++)
    {
        if (!vis1[i])
            temp++;
    }
    ans += (temp)*calA(n - num);
    vis1[p[num]] = 1;
    for (int i = num + 1; i <= n; i++)
    {
        int temp = 0;
        for (int j = p[i] + 1; j <= n; j++)
        {
            if (!vis1[j])
                temp++;
        }
        ans += (temp)*calA(n - i);
        vis1[p[i]] = 1;
    }
    vis2[q[num]] = 1;
    for (int i = num + 1; i <= n; i++)
    {
        int temp = 0;
        for (int j = 1; j < q[i]; j++)
        {
            if (!vis2[j])
                temp++;
        }
        ans += (temp)*calA(n - i);
        vis2[q[i]] = 1;
    }
    cout << ans << endl;
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