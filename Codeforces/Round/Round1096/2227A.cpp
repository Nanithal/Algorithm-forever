// https://codeforces.com/problemset/problem/2227/A

#include <iostream>
using namespace std;
int x, y;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> x >> y;
        if ((x & 1) && (y & 1))
            cout << "NO" << '\n';
        else
            cout << "YES" << '\n';
    }
    return 0;
}