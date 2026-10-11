// // https://codeforces.com/contest/2264/problem/C

// // 每一个数只会出现一次，则树的的即为最大的那个数
// // 首先讲输入按照从小到大的顺序排序
// // 那么对于第i个数a(i)，它在挑选父节点时，只能挑选a(j)(j > i)，则有(n - i)种选择
// // 那么最终能够形成的树的数量即为 (n - 1)*(n - 2)*....*1，即为(n - 1)!种
// // 在这么多树中，除了根节点外，其余节点一定都会成为某个数的子节点，那么减去的值即为 (n - 1)!*(a1+a2+...+a(n - 1))
// // 对于排序后的节点av来说，假设它的父节点是u(v < u)，边(v, u)在多少棵树中出现？----(n - 1)!/(n - v)
// // 因为固定节点av的父节点为au后，其余 n - 2 个非根节点(提出v和根节点n)的父节点任选，方案数为 (n - 1)*(n - 2)*...*(n - v +1)*(n - v -1)*...1
// // 即方案数为 (n - 1)!/(n - v)
// // 即对于固定的节点av，它作为子节点连接到任何合法父节点的数量都是(n - 1)!/(n - v)，令为 Ci
// // 那么父节点的提供的加上的值即为Ci * (a(i+1)+a(i+2)+...+a(n))  (可以搭配前缀和)
// // 令suf[i]为a[i]+a[i+1]+...+a[n]
// // 则总答案为 (n - 1)!/(n - i)*suf[i + 1] - (n + 1)!*a[i] (i 从 1 到 n -1)
// // 提取(n - 1)!，则ans = (n - 1)!*(suf[i + 1]/(n - i)-a[i]) mod 998244353

// // 最终结果即为父节点提供的加上的值 - 子节点提供的减去的值

// #include <bits/stdc++.h>
// #define endl '\n'
// using namespace std;
// using ll = long long;
// using ull = unsigned long long;
// const int N = 2e5 + 1;
// const int INF = 0x3f3f3f3f;
// const ll INFF = 0x3f3f3f3f3f3f3f3f;
// const ll MOD = 998244353;
// ll a[N], jiecheng[N];

// void init()
// {
//     jiecheng[0] = 1;
//     for (int i = 1; i < N; i++)
//         jiecheng[i] = jiecheng[i - 1] * i % MOD;
// }

// ll fast_pow(int x, int y)
// {
//     ll res = 1, temp = x;
//     while (y)
//     {
//         if (y & 1)
//         {
//             res *= temp;
//             res %= MOD;
//         }
//         y >>= 1;
//         temp *= temp;
//         temp %= MOD;
//     }
//     return res;
// }

// void solve()
// {
//     int n;
//     ll ans = 0, sum = 0;
//     cin >> n;
//     vector<ll> suf(n + 2);
//     suf[n + 1] = 0;
//     for (int i = 1; i <= n; i++)
//         cin >> a[i];
//     sort(a + 1, a + n + 1);
//     for (int i = n; i >= 1; i--)
//     {
//         suf[i] = (suf[i + 1] + a[i]) % MOD;
//     }
//     for (int i = 1; i < n; i++)
//     {
//         ll term = suf[i + 1] * fast_pow(n - i, MOD - 2) % MOD; // 求解逆
//         term = (term - a[i] % MOD + MOD) % MOD;
//         sum = (sum + term) % MOD;
//     }
//     ans = sum * jiecheng[n - 1] % MOD;
//     cout << ans << endl;
// }
// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     int t = 1;
//     cin >> t;
//     init();
//     while (t--)
//     {
//         solve();
//     }
//     return 0;
// }

// 下面是官方题解，也就是最优解

// 依旧是(n -1)!种棵树
// 然后用贡献法计算总代价
// 考虑每一条可能的边，计算它在多少棵树中出现，然后把这边的代价乘以出现次数，累加起来。
// 固定一条边：从子节点i连向父节点j,那这条边出现了多少次呢
// 固定后，其他节点k仍然可以自由选择父节点。
// 则方案数为 累乘(n - k -1)可以设为Wi
// 同时，对于固定的i，它可以连向所有的j > i，共有 n -i - 1种选择
// 因此所有从i出发的边的总贡献为W(i) *(aj-ai)(累加)
// 其中Wi的计算可以通过前后缀乘积相乘得到

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;

const int MOD = 998244353;

void solve()
{
    int n;
    cin >> n;
    vector<ll> b(n);
    for (int i = 0; i < n; i++)
        cin >> b[i];

    if (n == 1)
    {
        cout << 0 << '\n';
        return;
    }

    sort(b.begin(), b.end());

    // 计算 f[k] = n - k - 1，k 从 0 到 n-2
    // 前缀乘积 pre[i] = f[0] * ... * f[i-1]
    // 后缀乘积 suf[i] = f[i+1] * ... * f[n-2]
    vector<ll> pre(n - 1, 1), suf(n - 1, 1);
    for (int i = 1; i <= n - 2; i++)
    {
        // f[i-1] = n - (i-1) - 1 = n - i
        pre[i] = pre[i - 1] * (n - i) % MOD;
    }
    for (int i = n - 3; i >= 0; i--)
    {
        // f[i+1] = n - (i+1) - 1 = n - i - 2
        suf[i] = suf[i + 1] * (n - i - 2) % MOD;
    }

    // 后缀和：suffix_sum[i] = b[i] + b[i+1] + ... + b[n-1]
    vector<ll> suffix_sum(n + 1, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        suffix_sum[i] = (suffix_sum[i + 1] + b[i]) % MOD;
    }

    ll ans = 0;
    for (int i = 0; i <= n - 2; i++)
    {
        ll Wi = pre[i] * suf[i] % MOD; // W_i
        ll cnt = n - i - 1;            // j > i 的个数
        ll term = (suffix_sum[i + 1] - cnt % MOD * b[i] % MOD + MOD) % MOD;
        ans = (ans + Wi * term) % MOD;
    }

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}