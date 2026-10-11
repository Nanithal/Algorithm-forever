

#include <iostream>
using namespace std;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int sum = a + b + c;
    if (a == b && b == c)
        sum += 100;
    cout << sum << '\n';
    return 0;
}