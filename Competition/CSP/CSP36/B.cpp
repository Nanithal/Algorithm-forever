#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
int n;
long long a[N], b[N], c[N], d[N], mmm = 0;
void getans(int x)
{
    cout << a[0] + max(mmm, d[x] + b[x]) << ' ';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        c[i] = c[i - 1] + a[i] - b[i];
        mmm = max(mmm, c[i]);
    }
    d[n] = c[n];
    for (int i = n - 1; i >= 1; i--)
    {
        d[i] = max(c[i], d[i + 1]);
    }
    for (int i = 1; i <= n; i++)
    {
        getans(i);
    }
    return 0;
}
// long long a[N], b[N], c[N];
// long long tree[N << 2];
// void push_up(int rt)
// {
//     tree[rt] = max(tree[rt << 1], max(tree[rt << 1] + tree[rt << 1 | 1], tree[rt << 1 | 1]));
// }
// void build(int rt, int l, int r)
// {
//     if (l == r)
//     {
//         tree[rt] = c[l];
//         return;
//     }
//     int mid = l + ((r - l) >> 1);
//     build(rt << 1, l, mid);
//     build(rt << 1 | 1, mid + 1, r);
//     push_up(rt);
// }
// long long query()
// {
//     if (tree[1] < 0)
//         tree[1] = 0;
//     return tree[1] + a[0];
// }
// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cin >> n;
//     for (int i = 0; i <= n; i++)
//         cin >> a[i];
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> b[i];
//         c[i] = a[i] - b[i];
//     }
//     for (int i = 1; i <= n; i++)
//     {
//         long long temp = c[i];
//         c[i] = a[i];
//         build(1, 1, n);
//         cout << query() << ' ';
//         c[i] == temp;
//     }
// }