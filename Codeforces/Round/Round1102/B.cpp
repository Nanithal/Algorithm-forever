#include <iostream>
using namespace std;
long long n;
void solve()
{
    cin >> n;
    for (long long i = 0; i <= min(n, (long long)11); i++)
    {
        if (i == 10)
            continue;
        if ((n - i) % 12 == 0)
        {
            cout << i << ' ' << n - i << endl;
            return;
        }
    }
    if (n >= 22 && n % 12 == 10)
    {
        cout << 22 << ' ' << n - 22 << endl;
        return;
    }
    cout << "-1" << endl;
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