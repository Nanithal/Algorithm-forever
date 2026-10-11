

// #include <iostream>
// using namespace std;
// const int N = 5e5 + 2;
// int line[N];
// int line1[N];
// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     int n, k;
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> line[i];
//         line1[line[i]] = i;
//     }
//     cin >> k;
//     for (int i = 1; i <= k; i++)
//     {
//         int l, r;
//         cin >> l >> r;
//         if (r - l == n - 1 || (r - l == n - 2 && (line1[n] < l || line1[n] > r)))
//             cout << "peace" << '\n';
//         else
//         {
//             int now = 1;
//             while (line1[now] >= l && line1[now] <= r && now <= n)
//             {
//                 now++;
//             }
//             cout << now << '\n';
//             // int temp1 = line1[now], temp2 = line1[now + 1];
//             swap(line[line1[now]], line[line[now + 1]]);
//             swap(line1[now], line1[now + 1]);
//         }
//     }
//     return 0;
// }
#include <iostream>
using namespace std;
const int N = 5e5 + 2;
int line[N], line1[N];

// 线段树：维护区间内 pos[x] 的最小值和最大值
struct SegTree
{
    int minPos[N * 4], maxPos[N * 4];

    void build(int u, int l, int r)
    {
        if (l == r)
        {
            minPos[u] = maxPos[u] = line1[l];
            return;
        }
        int mid = (l + r) / 2;
        build(u * 2, l, mid);
        build(u * 2 + 1, mid + 1, r);
        minPos[u] = min(minPos[u * 2], minPos[u * 2 + 1]);
        maxPos[u] = max(maxPos[u * 2], maxPos[u * 2 + 1]);
    }

    void update(int u, int l, int r, int x, int val)
    {
        if (l == r)
        {
            minPos[u] = maxPos[u] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (x <= mid)
            update(u * 2, l, mid, x, val);
        else
            update(u * 2 + 1, mid + 1, r, x, val);
        minPos[u] = min(minPos[u * 2], minPos[u * 2 + 1]);
        maxPos[u] = max(maxPos[u * 2], maxPos[u * 2 + 1]);
    }

    // 查询最小的 x，使得 pos[x] 不在 [L, R] 内
    int query(int u, int l, int r, int L, int R)
    {
        if (l == r)
            return l;
        int mid = (l + r) / 2;
        // 先看左半区间是否有数不在 [L, R] 内
        if (minPos[u * 2] < L || maxPos[u * 2] > R)
        {
            return query(u * 2, l, mid, L, R);
        }
        return query(u * 2 + 1, mid + 1, r, L, R);
    }
} seg;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> line[i];
        line1[line[i]] = i;
    }

    seg.build(1, 1, n);

    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        int l, r;
        cin >> l >> r;

        if (r - l == n - 1 || (r - l == n - 2 && (line1[n] < l || line1[n] > r)))
        {
            cout << "peace" << '\n';
        }
        else
        {
            int now = seg.query(1, 1, n, l, r);
            cout << now << '\n';

            // 交换 now 和 now+1
            swap(line[line1[now]], line[line1[now + 1]]);
            swap(line1[now], line1[now + 1]);

            // 更新线段树
            seg.update(1, 1, n, now, line1[now]);
            seg.update(1, 1, n, now + 1, line1[now + 1]);
        }
    }
    return 0;
}