#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;

void solve()
{
    int a, b = 1, c;
    cin >> a;

    if (a == 1)
    {
        cout << 2 << ' ' << 3 << endl;
        return;
    }

    if (a == 1000000000)
    {
        cout << 536870912 << ' ' << 463129088 << endl;
        return;
    }
    b = 1;
    if (a & 1)
        c = a - 1;
    else
        c = a + 1;

    cout << b << ' ' << c << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    if (cin >> t)
    {
        while (t--)
        {
            solve();
        }
    }
    return 0;
}