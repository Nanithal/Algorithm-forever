// https://www.nowcoder.com/practice/addd700d4f4647a3b32ccaf42f5147fb?channelPut=tracker2

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
const int N = 5e5 + 1;
int opt, n, q;

// ll b[N];
// inline int lowbit(int x)
// {
//     return x & -x;
// }
// void add(int x, ll v)
// {
//     for (int i = x; i <= n; i += lowbit(i))
//         b[i] += v;
// }
// ll sum(int x)
// {
//     ll res = 0;
//     for (int i = x; i > 0; i -= lowbit(i))
//         res += b[i];
//     return res;
// }
// void range_add(int l, int r, ll v)
// {
//     add(l, v);
//     add(r + 1, -v);
// }
// ll query(int x)
// {
//     return sum(x);
// }
// void solve2()
// {
//     cin >> n >> q;
//     for (int i = 1; i <= n; i++)
//     {
//         ll temp;
//         cin >> temp;
//         range_add(i, i, temp);
//     }
//     for (int i = 1; i <= q; i++)
//     {
//         cin >> opt;
//         if (opt & 1)
//         {
//             int l, r;
//             ll v;
//             cin >> l >> r >> v;
//             range_add(l, r, v);
//         }
//         else
//         {
//             int x;
//             cin >> x;
//             cout << query(x) << endl;
//         }
//     }
// }

ll a[N], tree[N << 2];
ll lazy[N << 2];
void push_up(int rt)
{
    tree[rt] = tree[rt << 1] + tree[rt << 1 | 1];
}
void build(int rt, int l, int r)
{
    if (l == r)
    {
        tree[rt] = a[l];
        return;
    }
    int mid = l + ((r - l) >> 1);
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    push_up(rt);
}
void push_down(int rt, int l, int r)
{
    if (lazy[rt])
    {
        int mid = l + ((r - l) >> 1);

        tree[rt << 1] += lazy[rt] * (mid - l + 1);
        lazy[rt << 1] += lazy[rt];

        tree[rt << 1 | 1] += lazy[rt] * (r - mid);
        lazy[rt << 1 | 1] += lazy[rt];

        lazy[rt] = 0;
    }
}
void update(int rt, int l, int r, int ql, int qr, ll v)
{
    if (ql <= l && r <= qr)
    {
        tree[rt] += v * (r - l + 1);
        lazy[rt] += v;
        return;
    }
    push_down(rt, l, r);
    int mid = l + ((r - l) >> 1);
    if (ql <= mid)
        update(rt << 1, l, mid, ql, qr, v);
    if (qr > mid)
        update(rt << 1 | 1, mid + 1, r, ql, qr, v);
    push_up(rt);
}
ll query(int rt, int l, int r, int ql, int qr)
{
    if (ql <= l && r <= qr)
        return tree[rt];
    push_down(rt, l, r);
    int mid = l + ((r - l) >> 1);
    ll sum = 0;
    if (ql <= mid)
        sum += query(rt << 1, l, mid, ql, qr);
    if (qr > mid)
        sum += query(rt << 1 | 1, mid + 1, r, ql, qr);
    return sum;
}
void solve1()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    for (int i = 1; i <= q; i++)
    {
        cin >> opt;
        if (opt & 1)
        {
            int l, r;
            ll v;
            cin >> l >> r >> v;
            update(1, 1, n, l, r, v);
        }
        else
        {
            int x;
            cin >> x;
            cout << query(1, 1, n, x, x) << endl;
        }
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
        solve1();
    }
    return 0;
}