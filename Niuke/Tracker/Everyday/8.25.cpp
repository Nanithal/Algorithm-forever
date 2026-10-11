#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a;
    int res = 0;
    cin >> a;
    while (cin >> a)
    {
        res += __builtin_ctz(a);
    }
    cout << res;
}
