// #include <iostream>
// using namespace std;
// const int N = 2e5 + 1;

// int n, t;
// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cin >> t;
//     while (t--)
//     {
//         long long a[N] = {0};
//         cin >> n;
//         for (int i = 1; i <= n; i++)
//             cin >> a[i];
//         if (n == 1)
//             cout << "YES" << '\n';
//         else
//         {
//             bool ok = 1;
//             long long ans = 1e9;
//             for (int i = 2; i <= n; i++)
//             {
//                 if (a[i - 1] > a[i])
//                 {
//                     long long maxn = max(a[i - 1], a[i + 1]);
//                     if (maxn - a[i] > ans)
//                     {
//                         ok = 0;
//                         break;
//                     }
//                     else
//                     {
//                         ans = maxn - a[i];
//                         long long add = maxn - a[i];
//                         int j = i + 1;
//                         while (j <= n && a[j] < maxn && a[j] >= a[j - 1])
//                         {
//                             j++;
//                         }
//                         for (int k = i; k <= j - 1; k++)
//                             a[k] += add;
//                         i = j - 1;
//                     }
//                 }
//             }
//             if (ok)
//                 cout << "YES" << '\n';
//             else
//                 cout << "NO" << '\n';
//         }
//     }
//     return 0;
// }

#include <iostream>
#include <vector>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int maxn = 0;
    for (int i = 2; i <= n; i++)
    {
        if (a[i - 1] > a[i])
            maxn = max(maxn, a[i - 1] - a[i]);
    }
    bool ok = 1;
    for (int i = 2; i <= n; i++)
    {
        if (a[i] < a[i - 1])
            a[i] += maxn;
        if (a[i] < a[i - 1])
        {
            ok = 0;
            break;
        }
    }
    if (ok)
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
// #include <vector>
// #include <list>
// #include <map>
// #include <set>
// #include <deque>
// #include <vector>
// #include <list>
// #include <map>
// #include <set>
// #include <deque>
// #include <queue>
// #include <stack>
// #include <bitset>
// #include <algorithm>
// #include <functional>
// #include <numeric>
// #include <utility>
// #include <sstream>
// #include <iostream>
// #include <iomanip>
// #include <cstdio>
// #include <cmath>
// #include <cstdlib>
// #include <cctype>
// #include <string>
// #include <cstring>
// #include <ctime>
// #include <random>
// #include <chrono>

// using namespace std;

// #define _int64 long long
// #define mo 998244353

// int a[210000];

// int main()
// {
//     int i, j, k, n, l, t, m, x, y, o, b1, mi;
//     scanf("%d", &t);
//     for (l = 0; l < t; l++)
//     {
//         scanf("%d", &n);
//         for (i = 0; i < n; i++)
//             scanf("%d", &a[i]);
//         mi = 0;
//         for (i = 0; i + 1 < n; i++)
//             if (a[i + 1] < a[i])
//                 mi = max(mi, a[i] - a[i + 1]);
//         for (i = 1; i < n; i++)
//             if (a[i] < a[i - 1])
//                 a[i] += mi;
//         b1 = 1;
//         for (i = 0; i + 1 < n; i++)
//             if (a[i + 1] < a[i])
//                 b1 = 0;
//         if (b1 == 1)
//             printf("YES\n");
//         else
//             printf("NO\n");
//     }
// }