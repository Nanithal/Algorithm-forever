// https://codeforces.com/gym/105937/problem/N

// 线段树

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 5e5 + 1;

int tree[N << 2];
int line[N];
int line1[N];
int n, k, l, r;

void push_up(int rt)
{
    tree[rt] = min(tree[rt << 1], tree[rt << 1 | 1]);
}

void build(int rt, int l, int r)
{
    if (l == r)
    {
        tree[rt] = line[l];
        return;
    }
    int mid = l + ((r - l) >> 1);
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    push_up(rt);
}
int query(int rt, int l, int r, int L, int R)
{
    if (l >= L && r <= R)
        return tree[rt];
    int mid = l + ((r - l) >> 1);
    int res = N;
    if (L <= mid)
    {
        res = min(res, query(rt << 1, l, mid, L, R));
    }
    if (R > mid)
    {
        res = min(res, query(rt << 1 | 1, mid + 1, r, L, R));
    }
    return res;
}
void update(int rt, int l, int r, int x, int v)
{
    if (l == r)
    {
        tree[rt] = v;
        return;
    }
    int mid = l + ((r - l) >> 1);
    if (x <= mid)
    {
        update(rt << 1, l, mid, x, v);
    }
    else
    {
        update(rt << 1 | 1, mid + 1, r, x, v);
    }
    push_up(rt);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> line[i];
        line1[line[i]] = i;
    }
    build(1, 1, n);
    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        cin >> l >> r;
        int p1, p2;
        p1 = p2 = N;
        if (l != 1)
            p1 = query(1, 1, n, 1, l - 1);
        if (r != n)
            p2 = query(1, 1, n, r + 1, n);
        int x = min(p1, p2);
        if (x >= n)
            cout << "peace" << '\n';
        else
        {
            cout << x << '\n';
            int loc1 = line1[x];
            int loc2 = line1[x + 1];
            line[loc1] = x + 1;
            line[loc2] = x;
            line1[x + 1] = loc1;
            line1[x] = loc2;
            update(1, 1, n, loc1, x + 1);
            update(1, 1, n, loc2, x);
        }
    }
    return 0;
}
