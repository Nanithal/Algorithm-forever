// https://atcoder.jp/contests/abc457/tasks/abc457_d

// 二分答案
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 2;
long long a[N], l = 1e18 + 1, r = 4e18, mid, k;
int n;
bool check(long long x)
{
    long long num = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] < x)
        {
            long long t = (x - a[i] + i - 1) / i;
            num += t;
        }
        if (num > k)
            return false;
    }
    return true;
}
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        l = min(l, a[i]);
    }
    while (l < r)
    {
        mid = l + ((r - l + 1) >> 1);
        if (check(mid))
        {
            l = mid;
        }
        else
            r = mid - 1;
    }
    cout << l << '\n';
    return 0;
}