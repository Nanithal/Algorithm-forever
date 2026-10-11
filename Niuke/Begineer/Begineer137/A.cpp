#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int INF = 0x3f3f3f3f;

void solve()
{
    int n;
    cin >> n;
    if (n <= 2)
    {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    cout << 836;
    for (int i = 1; i <= n - 3; i++)
        cout << 0;
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}