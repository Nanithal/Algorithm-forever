// // #include <bits/stdc++.h>
// // #define endl '\n'
// // using namespace std;
// // using ll = long long;
// // const ll INF = 0x3f3f3f3f3f3f3f3f;
// // void solve()
// // {
// //     int n, q, opt, l, r, ans = 0;
// //     string s;
// //     cin >> n >> q;
// //     cin >> s;
// //     s = ' ' + s;
// //     s = s + ' ';
// //     for (int i = 1; i <= n;)
// //     {
// //         if (s[i] == 'A')
// //         {
// //             int orig = i;
// //             while (s[i] == 'A' && i <= n)
// //                 i++;
// //             ans++;
// //         }
// //         else
// //             i++;
// //     }
// //     for (int i = 1; i <= q; i++)
// //     {
// //         cin >> opt;
// //         if (opt & 1)
// //         {
// //             cin >> l >> r;
// //             int L = l, R = r;
// //             if (s[l] == 'A')
// //             {
// //                 if (s[l - 1] != 'A')
// //                     ans--;
// //                 while (s[L] != 'C')
// //                     L++;
// //             }
// //             else if (s[l] == 'C')
// //             {
// //                 if (s[l - 1] != 'A')
// //                     ans++;
// //                 while (s[L] == 'C')
// //                     L++;
// //             }
// //             if (s[r] == 'A')
// //             {
// //                 if (s[r + 1] != 'A')
// //                     ans--;
// //                 while (s[L] != 'C')
// //                     L++;
// //             }
// //             if (s[r])
// //                 for (int i = l; i <= r; i++)
// //                 {
// //                     s[i] = 'A' + (s[i] - 'A' + 1) % 3;
// //                 }
// //         }
// //         else
// //         {
// //             cout << ans << endl;
// //         }
// //     }
// // }
// // int main()
// // {
// //     ios::sync_with_stdio(0);
// //     cin.tie(0);
// //     int t = 1;
// //     while (t--)
// //     {
// //         solve();
// //     }
// //     return 0;
// // }

// #include <bits/stdc++.h>
// #define endl '\n'
// using namespace std;
// using ll = long long;
// const ll INF = 0x3f3f3f3f3f3f3f3f;
// const int N = 2e5 + 5;
// char s[N];
// int tree[N << 2], lazy[N << 2];
// void push_up(int rt, int l, int r)
// {
//     int mid = l + ((r - l) >> 1);
//     tree[rt] = tree[rt << 1] + tree[rt << 1 | 1];
//     if (s[mid] == s[mid + 1] && s[mid] == 'A')
//         tree[rt] -= 1;
// }
// void push_down(int rt, int l, int r)
// {
//     if (lazy[rt] != 0)
//     {
//         int mid = l + ((r - l) >> 1);
//         lazy[rt << 1] += lazy[rt];
//         lazy[rt << 1 | 1] += lazy[rt];
//         lazy[rt] = 0;
//     }
// }
// void up_date(int rt, int l, int r, int ql, int qr)
// {
//     if (ql <= l && r <= qr)
//     {
//         lazy[rt] += 1;
//         return;
//     }
//     push_down(rt, l, r);
//     int mid = l + ((r - l) >> 1);
//     if (ql <= mid)
//         up_date(rt << 1, l, mid, ql, qr);
//     if (qr > mid)
//         up_date(rt << 1 | 1, mid + 1, r, ql, qr);
//     push_up(rt);
// }
// void build(int rt, int l, int r)
// {
//     if (l == r)
//     {
//         if (s[l] == 'A')
//             tree[rt] = 1;
//     }
//     int mid = l + ((r - l) >> 1);
//     build(rt << 1, l, mid);
//     build(rt << 1 | 1, mid + 1, r);
//     push_up();
// }
// void solve()
// {
//     int n, q, p;
//     string s;
//     cin >> n >> q;
//     cin >> s;
//     build(1, 1, n);
// }
// int query(int rt,int l,int r)
// {

// }
// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     int t = 1;
//     while (t--)
//     {
//         solve();
//     }
//     return 0;
// }

// // #include <bits/stdc++.h>
// // #define endl '\n'
// // using namespace std;
// // using ll = long long;
// // const ll INF = 0x3f3f3f3f3f3f3f3f;
// // void solve()
// // {
// //     int n, q, opt, l, r, ans = 0;
// //     string s;
// //     cin >> n >> q;
// //     cin >> s;
// //     s = ' ' + s;
// //     s = s + ' ';
// //     for (int i = 1; i <= n;)
// //     {
// //         if (s[i] == 'A')
// //         {
// //             int orig = i;
// //             while (s[i] == 'A' && i <= n)
// //                 i++;
// //             ans++;
// //         }
// //         else
// //             i++;
// //     }
// //     for (int i = 1; i <= q; i++)
// //     {
// //         cin >> opt;
// //         if (opt & 1)
// //         {
// //             cin >> l >> r;
// //             int L = l, R = r;
// //             if (s[l] == 'A')
// //             {
// //                 if (s[l - 1] != 'A')
// //                     ans--;
// //                 while (s[L] != 'C')
// //                     L++;
// //             }
// //             else if (s[l] == 'C')
// //             {
// //                 if (s[l - 1] != 'A')
// //                     ans++;
// //                 while (s[L] == 'C')
// //                     L++;
// //             }
// //             if (s[r] == 'A')
// //             {
// //                 if (s[r + 1] != 'A')
// //                     ans--;
// //                 while (s[L] != 'C')
// //                     L++;
// //             }
// //             if (s[r])
// //                 for (int i = l; i <= r; i++)
// //                 {
// //                     s[i] = 'A' + (s[i] - 'A' + 1) % 3;
// //                 }
// //         }
// //         else
// //         {
// //             cout << ans << endl;
// //         }
// //     }
// // }
// // int main()
// // {
// //     ios::sync_with_stdio(0);
// //     cin.tie(0);
// //     int t = 1;
// //     while (t--)
// //     {
// //         solve();
// //     }
// //     return 0;
// // }

// #include <bits/stdc++.h>
// #define endl '\n'
// using namespace std;
// using ll = long long;
// const ll INF = 0x3f3f3f3f3f3f3f3f;
// const int N = 2e5 + 5;
// char s[N];
// int tree[N << 2], lazy[N << 2];
// void push_up(int rt, int l, int r)
// {
//     int mid = l + ((r - l) >> 1);
//     tree[rt] = tree[rt << 1] + tree[rt << 1 | 1];
//     if (s[mid] == s[mid + 1] && s[mid] == 'A')
//         tree[rt] -= 1;
// }
// void push_down(int rt, int l, int r)
// {
//     if (lazy[rt] != 0)
//     {
//         int mid = l + ((r - l) >> 1);
//         lazy[rt << 1] += lazy[rt];
//         lazy[rt << 1 | 1] += lazy[rt];
//         lazy[rt] = 0;
//     }
// }
// void up_date(int rt, int l, int r, int ql, int qr)
// {
//     if (ql <= l && r <= qr)
//     {
//         lazy[rt] += 1;
//         return;
//     }
//     push_down(rt, l, r);
//     int mid = l + ((r - l) >> 1);
//     if (ql <= mid)
//         up_date(rt << 1, l, mid, ql, qr);
//     if (qr > mid)
//         up_date(rt << 1 | 1, mid + 1, r, ql, qr);
//     push_up(rt);
// }
// void build(int rt, int l, int r)
// {
//     if (l == r)
//     {
//         if (s[l] == 'A')
//             tree[rt] = 1;
//     }
//     int mid = l + ((r - l) >> 1);
//     build(rt << 1, l, mid);
//     build(rt << 1 | 1, mid + 1, r);
//     push_up();
// }
// void solve()
// {
//     int n, q, p;
//     string s;
//     cin >> n >> q;
//     cin >> s;
//     build(1, 1, n);
// }
// int query(int rt,int l,int r)
// {

// }
// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     int t = 1;
//     while (t--)
//     {
//         solve();
//     }
//     return 0;
// }

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;

const int N = 200005;
char s[N];

int tree[N << 2][3];
bool l_is_A[N << 2][3], r_is_A[N << 2][3];
int lazy[N << 2];

void apply_lazy(int rt, int shift)
{
    shift %= 3;
    if (shift == 0)
        return;
    lazy[rt] = (lazy[rt] + shift) % 3;

    int new_tree[3];
    bool new_l[3], new_r[3];
    for (int k = 0; k < 3; k++)
    {
        int prev_k = (k + shift) % 3; // 改为加 shift
        new_tree[k] = tree[rt][prev_k];
        new_l[k] = l_is_A[rt][prev_k];
        new_r[k] = r_is_A[rt][prev_k];
    }
    for (int k = 0; k < 3; k++)
    {
        tree[rt][k] = new_tree[k];
        l_is_A[rt][k] = new_l[k];
        r_is_A[rt][k] = new_r[k];
    }
}
void push_up(int rt)
{
    int ls = rt << 1, rs = rt << 1 | 1;
    for (int k = 0; k < 3; k++)
    {
        tree[rt][k] = tree[ls][k] + tree[rs][k] - (r_is_A[ls][k] && l_is_A[rs][k] ? 1 : 0);
        l_is_A[rt][k] = l_is_A[ls][k];
        r_is_A[rt][k] = r_is_A[rs][k];
    }
}

void push_down(int rt)
{
    if (lazy[rt] != 0)
    {
        apply_lazy(rt << 1, lazy[rt]);
        apply_lazy(rt << 1 | 1, lazy[rt]);
        lazy[rt] = 0;
    }
}

void build(int rt, int l, int r)
{
    lazy[rt] = 0;
    if (l == r)
    {
        int orig = s[l] - 'A';
        for (int k = 0; k < 3; k++)
        {
            int cur = (orig + k) % 3;
            if (cur == 0)
            {
                tree[rt][k] = 1;
                l_is_A[rt][k] = true;
                r_is_A[rt][k] = true;
            }
            else
            {
                tree[rt][k] = 0;
                l_is_A[rt][k] = false;
                r_is_A[rt][k] = false;
            }
        }
        return;
    }
    int mid = l + ((r - l) >> 1);
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    push_up(rt);
}

void up_date(int rt, int l, int r, int ql, int qr)
{
    if (ql <= l && r <= qr)
    {
        apply_lazy(rt, 1);
        return;
    }
    push_down(rt);
    int mid = l + ((r - l) >> 1);
    if (ql <= mid)
        up_date(rt << 1, l, mid, ql, qr);
    if (qr > mid)
        up_date(rt << 1 | 1, mid + 1, r, ql, qr);
    push_up(rt);
}

void solve()
{
    int n, q, opt, l, r;
    if (!(cin >> n >> q))
        return;
    for (int i = 1; i <= n; i++)
        cin >> s[i];

    build(1, 1, n);

    while (q--)
    {
        cin >> opt;
        if (opt == 1)
        {
            cin >> l >> r;
            up_date(1, 1, n, l, r);
        }
        else if (opt == 2)
        {
            cout << tree[1][0] << endl;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}