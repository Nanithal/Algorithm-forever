// 大赛第11题每日任务
// 此题对于小数据来说可以采用深搜，但只能拿部分分

//================深搜==================
// #include <iostream>
// #include <algorithm>
// const int N = 1e5 + 10;
// class a
// {
// public:
//     int value;
//     int rest_day;
// };
// a day[N];
// int n;
// long long ans = 0;
// using namespace std;
// void dfs(int d, int cur)
// {
//     if (d > n)
//     {
//         if (cur > ans)
//             ans = cur;
//         return;
//     }
//     dfs(d + day[d].rest_day + 1, cur + day[d].value);
//     dfs(d + 1, cur);
// }
// int main()
// {
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//         cin >> day[i].value;
//     for (int i = 1; i <= n; i++)
//         cin >> day[i].rest_day;
//     dfs(1, 0);
//     cout << ans;
//     return 0;
// }

//=========================DP====================
// 考虑采用倒序DP，令f(i)表示第i天到第n天的最大收益
// 分类讨论如下：
// 若未选择第i天的任务，则从f(i+1)转移
// 若选择第i天的任务，则从f(i+d(i)+1)转移
// 则状态转移如下：f(i)=max(f(i+1),f(i+d(i)+1)+a(i)));
#include <iostream>
#include <algorithm>
const int N = 1e6 + 10;
class a
{
public:
    int value;
    int rest_day;
} day[N];
long long f[N];
int n;
using namespace std;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> day[i].value;
    for (int i = 1; i <= n; i++)
        cin >> day[i].rest_day;
    f[n] = day[n].value;
    for (int i = n - 1; i >= 1; i--)
    {
        f[i] = max(f[i + 1], f[i + day[i].rest_day + 1] + day[i].value);
    }
    cout << f[1] << '\n';
    return 0;
}
