

// #include <iostream>
// #include <vector>
// using namespace std;

// const int N = 1e5 + 1;
// int leng_sum[N];
// int wide_sum[N];
// int heig_sum[N];
// vector<int> l1;
// vector<int> l2;
// vector<int> l3;
// int n, a, b, c, ans = 0;
// int x1, y1, z1, x2, y2, z2;
// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cin >> n >> a >> b >> c;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
//         int sma = min(x1, x2);
//         l1.push_back(sma);
//         int big = max(x1, x2);
//         leng_sum[sma] += 1;
//         if (sma != big)
//         {
//             leng_sum[big] += (big - sma) + 1;
//             l1.push_back(big);
//         }
//         sma = min(y1, y2);
//         l2.push_back(sma);
//         big = max(y1, y2);
//         wide_sum[y1] += 1;
//         if (sma != big)
//         {
//             wide_sum[y1] += (big - sma + 1);
//             l2.push_back(big);
//         }
//         sma = min(z1, z2);
//         big = max(z1, z2);
//         heig_sum[z1] += 1;
//         if (sma != big)
//         {
//             heig_sum[z2] -= (big - sma + 1);
//             l3.push_back(big);
//         }
//     }
//     for (int i = l1.size() - 1; i >= 1; i--)
//     {
//         ans = max(ans, leng_sum[l1[i]] - leng_sum[i - 1] + 1);
//     }
//     for (int i = l2.size() - 1; i >= 1; i--)
//     {
//         ans = max(ans, leng_sum[l2[i]] - leng_sum[l2[i - 1]] + 1);
//     }
//     for (int i = l3.size() - 1; i >= 1; i--)
//     {
//         ans = max(ans, leng_sum[l3[i]] - leng_sum[l3[i - 1]] + 1);
//     }
//     cout << ans << '\n';
//     return 0;
// }

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 1;
struct len
{
public:
    int l;
    int r;
} leng[N];
struct wid
{
public:
    int l;
    int r;
} wide[N];
struct hei
{
public:
    int l;
    int r;
} heig[N];
bool com1(len &a, len &b)
{
    return a.l <= b.l;
}
bool com2(wid &a, wid &b)
{
    return a.l <= b.l;
}
bool com3(hei &a, hei &b)
{
    return a.l <= b.l;
}
int n, a, b, c, ans = 0;
int x1, y1, z1, x2, y2, z2;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> a >> b >> c;
    for (int i = 1; i <= n; i++)
    {
        cin >> leng[i].l >> wide[i].l >> heig[i].l >> leng[i].r >> wide[i].r >> heig[i].r;
    }
    sort(leng + 1, leng + n + 1, com1);
    sort(wide + 1, wide + n + 1, com2);
    sort(heig + 1, heig + n + 1, com3);
    int now = 1, temp = 1;
    for (int i = 2; i <= n; i++)
    {
        if (leng[i].l <= leng[now].r)
        {
            temp++;
            now = leng[i].r > leng[i].r ? i : now;
            continue;
        }
        ans = max(temp, ans);
        now = i;
        temp = 1;
    }
    now = 1, temp = 1;
    for (int i = 2; i <= n; i++)
    {
        if (wide[i].l <= wide[now].r)
        {
            temp++;
            now = wide[i].r > wide[i].r ? i : now;
            continue;
        }
        ans = max(temp, ans);
    }
    now = 1, temp = 1;
    for (int i = 2; i <= n; i++)
    {
        if (heig[i].l <= heig[now].r)
        {
            temp++;
            now = heig[i].r > heig[i].r ? i : now;
            continue;
        }
        ans = max(temp, ans);
    }
    cout << ans << '\n';
    return 0;
}