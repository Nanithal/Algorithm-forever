#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;
int a[N];
int tree[N << 2];
int n, l, r, res;
int query(int rt, int l, int r, int ql, int qr)
{
    if (l >= ql && r <= qr)
    {
        return tree[rt];
    }
    int mid = l + ((r - l) >> 1);
    int ans = 0;
    if (mid >= ql)
        ans |= query(rt << 1, l, mid, ql, qr);
    if (mid < qr)
        ans |= query(rt << 1 | 1, mid + 1, r, ql, qr);
    return ans;
}
bool check(int t)
{
    int range = (t + 1) * t / 2;
    for (int i = 1; i <= n; i++)
    {
        if (range + i <= n)
        {
            if (query(1, 1, n, i, i + range) != res)
                return false;
        }
        else
        {
            if (((query(1, 1, n, i, n) | query(1, 1, n, 1, range - n + i)) != res))
                return false;
        }
    }
    return true;
}
void push_up(int rt)
{
    tree[rt] = tree[rt << 1] | tree[rt << 1 | 1];
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
void solve()
{
    res = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        res |= a[i];
    }
    build(1, 1, n);
    l = 0, r = ceil((sqrt(2.0 * n - 1.75) - 0.5));
    while (l < r)
    {
        int mid = l + ((r - l) >> 1);
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << '\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}