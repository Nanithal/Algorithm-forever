// #include <bits/stdc++.h>
// #define endl '\n'
// using namespace std;
// using ll = long long;
// int n, q, l, r;
// void solve()
// {
//     map<int, vector<int>> ma;
//     cin >> n >> q;
//     vector<int> a(n + 1, 0);
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> a[i];
//         ma[a[i]].push_back(i);
//     }
//     for (int i = 1; i <= q; i++)
//     {
//         cin >> l >> r;
//         int up = r - l + 1;
//         if (up & 1)
//         {
//             cout << "N0" << endl;
//         }
//         else
//         {
//             up /= 2;
//             bool ok = 1;
//             for (int j = 1; j <= up; j++)
//             {
//                 if (ma[j].size() < 2)
//                 {
//                     ok = 0;
//                     break;
//                 }
//                 int num = 0;
//                 for (int k = 0; k < ma[j].size(); k++)
//                 {
//                     if (ma[j][k] >= l && ma[j][k] <= r)
//                         num++;
//                     if (num > 2)
//                     {
//                         ok = 0;
//                         break;
//                     }
//                 }
//                 if (num != 2)
//                 {
//                     ok = 0;
//                     break;
//                 }
//             }
//             if (ok)
//                 cout << "Yes" << endl;
//             else
//                 cout << "No" << endl;
//         }
//     }
// }
// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     int t = 1;
//     // cin >> t;
//     while (t--)
//     {
//         solve();
//     }
//     return 0;
// }

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ull = unsigned long long;
const int N = 2.5e+5;
int a[N];
ull v1[N], v2[N]; // 两个随机权值数组
ull px[N], ps[N]; // 前缀异或和，前缀加法和
ull tg[N];        // 目标加法和·····························

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count()); // 返回ull的整形数据

void solve()
{
    int n, q;
    if (!(cin >> n >> q))
        return;

    // 生成随机权值
    for (int i = 1; i <= n; i++)
    {
        v1[i] = rng();
        v2[i] = rng();
    }

    // 预处理目标和 tg[m] = 2 * sum(v2[1...m])
    ull cur = 0;
    for (int i = 1; i <= n / 2; i++)
    {
        cur += 2 * v2[i];
        tg[i] = cur;
    }

    // 建前缀和
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] <= n)
        {
            px[i] = px[i - 1] ^ v1[a[i]];
            ps[i] = ps[i - 1] + v2[a[i]];
        }
        else
        {
            px[i] = px[i - 1] ^ rng();
            ps[i] = ps[i - 1] + rng();
        }
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int len = r - l + 1;
        if (len & 1)
        {
            cout << "No" << endl;
            continue;
        }
        int m = len / 2;
        ull rx = px[r] ^ px[l - 1];
        ull rs = ps[r] - ps[l - 1];
        if (rx == 0 && rs == tg[m])
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
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