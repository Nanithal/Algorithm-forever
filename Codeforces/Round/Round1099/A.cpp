#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            if (i & 1)
                cout << n - i / 2 << ' ';
            else
                cout << 2 * n - (i - 1) / 2 << ' ';
        }
        cout << '\n';
    }
    return 0;
}