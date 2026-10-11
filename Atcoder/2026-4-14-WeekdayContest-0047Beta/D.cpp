// https://atcoder.jp/contests/awc0047/tasks/awc0047_d

//===============模拟（可能超时）==================
// #include <iostream>
// #include <algorithm>
// using namespace std;
// const int N = 2e5 + 10;
// int chi[N];
// int main()
// {
//     int n;
//     cin >> n;
//     long long sum = 0, ans = 0;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> chi[i];
//         sum += chi[i];
//     }
//     if (sum % n)
//     {
//         cout << -1;
//         return 0;
//     }
//     int average = sum / n;
//     for (int i = n; i >= 2; i--)
//     {
//         if (chi[i] < average)
//         {
//             int need = average - chi[i], t = 1;
//             while (need > 0)
//             {
//                 int x = min(chi[i - t], need);
//                 ans += t * x;
//                 chi[i - t] -= x;
//                 need -= x;
//                 t++;
//             }
//         }
//         else if (chi[i] > average)
//         {
//             int x = chi[i] - average;
//             chi[i - 1] += x;
//             ans += x;
//             chi[i] = average;
//         }
//     }
//     cout << ans << '\n';
//     return 0;
// }

//=========前缀和==============
// 这是典型的直线型均分纸牌，ans=前缀和绝对值之和
// 若是环形均分纸牌，ans=排序后中位数距离之和
// 每一个位置，都必须把当前所有盈余/缺口传给下一个，代价就是当前前缀和的绝对值，全部加起来就是最小代价
#include <iostream>
#include <cmath>
using namespace std;

const int N = 2e5 + 10;
typedef long long ll;

ll a[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    ll sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        sum += a[i];
    }

    if (sum % n != 0)
    {
        cout << -1 << endl;
        return 0;
    }

    ll avg = sum / n;
    ll s = 0, ans = 0;

    for (int i = 1; i <= n; ++i)
    {
        s += a[i] - avg;
        ans += abs(s);
    }

    cout << ans << endl;
    return 0;
}