#include <iostream>
#include <algorithm>
int a[8];
using namespace std;
int main()
{
    int t, sum;
    cin >> t;
    for (int j = 1; j <= t; j++)
    {
        sum = 0;
        for (int i = 1; i <= 7; i++)
            cin >> a[i];
        sort(a + 1, a + 8);
        for (int i = 1; i <= 6; i++)
            sum += -a[i];
        sum += a[7];
        cout << sum << '\n';
    }
    return 0;
}