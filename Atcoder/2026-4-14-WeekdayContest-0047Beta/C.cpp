// https://atcoder.jp/contests/awc0047/tasks/awc0047_c
// 树状数组

//==========暴力（会超时）=======
// #include <iostream>
// using namespace std;
// const int N = 2e5 + 10;
// long long save[N];
// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     int n, q;
//     cin >> n >> q;
//     for (int i = 1; i <= n; i++)
//         cin >> save[i];
//     for (int i = 1; i <= q; i++)
//     {
//         int selection;
//         cin >> selection;
//         if (selection == 1)
//         {
//             int l, r, x;
//             cin >> l >> r >> x;
//             for (int i = l; i <= r; i++)
//                 save[i] += x;
//         }
//         else
//         {
//             int p;
//             cin >> p;
//             cout << save[p] << '\n';
//         }
//     }
//     return 0;
// }

//============前缀和、差分（也会超时）==============
// #include <iostream>
// using namespace std;
// const int N = 2e5 + 10;
// long long save[N], chafen[N]; // 新增差分数组diff
// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     int n, q;
//     cin >> n >> q;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> save[i];
//         chafen[i] = save[i] - save[i - 1];
//     }
//     for (int i = 1; i <= q; i++)
//     {
//         int op;
//         cin >> op;
//         if (op == 1)
//         {
//             int l, r, x;
//             cin >> l >> r >> x;
//             chafen[l] += x;
//             chafen[r + 1] -= x;
//         }
//         else
//         {
//             int p;
//             cin >> p;
//             long long ans = 0;
//             for (int j = 1; j <= p; j++)
//                 ans += chafen[j];
//             cout << ans << '\n';
//         }
//     }
//     return 0;
// }

//===============树状数组（板子）==================
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, q;
long long tree[N];
// lowbit
int lowbit(int x)
{
    return x & -x;
}
// 单点加（在差分数组上操作）
void add(int x, long long v)
{
    for (int i = x; i <= n; i += lowbit(i))
        tree[i] += v;
}
// 前缀和（得到原数组的某个点值）
long long sum(int x)
{
    long long res = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        res += tree[i];
    return res;
}
// 区间修改 [l, r] + v
void range_add(int l, int r, long long v)
{
    add(l, v);
    add(r + 1, -v);
}

// 单点查询：查询第x个数
long long query(int x)
{
    return sum(x);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    // 初始化
    for (int i = 1; i <= n; i++)
    {
        long long x;
        cin >> x;
        range_add(i, i, x); // 建立差分
    }
    for (int i = 1; i <= q; i++)
    {
        int opi;
        cin >> opi;
        if (opi == 1)
        {
            int l, r, x;
            cin >> l >> r >> x;
            range_add(l, r, x);
        }
        else
        {
            int p;
            cin >> p;
            cout << query(p) << '\n';
        }
    }
    return 0;
}