// https://codeforces.com/contest/2233/problem/B
#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    if (n != 2)
    {
        for (int i = 1; i <= n; i++)
            cout << i << " " << i << ' ';
        for (int i = 1; i <= n - 2; i++)
            cout << i << ' ';
        for (int i = n; i >= n - 1; i--)
            cout << i << ' ';
        for (int i = 1; i <= n; i++)
            cout << i << ' ';
    }
    else
    {
        cout << "1 2 2 1 2 1 1 2";
    }
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}