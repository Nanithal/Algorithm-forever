// https://codeforces.com/problemset/problem/2232/B

// 前缀和+贪心
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    long long ans = 2e9;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        long long avg = sum / (i + 1);
        ans = min(ans, avg);
        cout << ans << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}