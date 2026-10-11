#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 1;
int a[N];
void solve()
{
    int n, k, maxn = 0;
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
    {
        cin >> a[i];
        maxn = max((a[i] - a[i - 1]) / 2, maxn);
    }
    maxn = max({maxn, a[1] - 1, n - a[k]});
    cout << maxn << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
    }
    return 0;
}