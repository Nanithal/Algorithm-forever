#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
// const int N = 1e6 + 2;
const int INF = 0x3f3f3f3f;
int n;
double score;
// class margin
// {
// public:
//     double l, r;
// } a[N];
// bool com(margin a, margin b)
// {
//     return a.l < b.l;
// }
// void solve()
// {
//     double L, R;
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> score;
//         a[i].l = score * 1.0 / i;
//         a[i].r = (score + 1.0) / i;
//     }
//     sort(a + 1, a + n + 1, com);
//     L = a[1].l;
//     R = a[1].r;
//     for (int i = 2; i <= n; i++)
//     {
//         if (a[i].l <= R)
//         {
//             L = max(L, a[i].l);
//             R = min(R, a[i].r);
//         }
//     }
//     cout << fixed << setprecision(6) << R << endl;
// }
void solve2()
{
    cin >> n;
    double res = INFINITY;
    for (int i = 1; i <= n; i++)
    {
        cin >> score;
        res = min((score + 1) / i, res);
    }
    cout << fixed << setprecision(6) << res << endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve2();
    }
    return 0;
}