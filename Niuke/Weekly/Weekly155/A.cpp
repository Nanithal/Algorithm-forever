#include <iostream>
using namespace std;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int num = 0;
    if (a)
        num++;
    if (b)
        num++;
    if (c)
        num++;
    if (num & 1)
    {
        cout << "ON\n";
    }
    else
        cout << "OFF\n";
    return 0;
}