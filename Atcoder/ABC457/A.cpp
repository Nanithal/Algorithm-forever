#include <iostream>
using namespace std;
int a[1100];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int x;
    cin >> x;
    cout << a[x] << '\n';
    return 0;
}