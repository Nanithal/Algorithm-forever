// https://codeforces.com/contest/2264/problem/A
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 2e5 + 1;
const int INF = 0x3f3f3f3f;
int a[101];
void solve()
{
    int n;
    cin >> n;
    vector<int> sa;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] != i)
            sa.push_back(i);
    }
    int l = 0, r = sa.size() - 1;
    bool ok = 1;
    while (l < r)
    {
        if (sa[l] != a[sa[r]] || sa[r] != a[sa[l]])
        {
            ok = false;
            break;
        }
        l++, r--;
    }
    if (ok)
        cout << "Yes\n";
    else
        cout << "No\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}