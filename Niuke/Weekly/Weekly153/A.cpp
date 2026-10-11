#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a;
    cin >> a;
    char c[7];
    c[0] = a[0];
    c[1] = '.';
    c[2] = a[1];
    c[3] = '.';
    c[4] = a[2];
    c[5] = '\0';
    cout << c << endl;
    return 0;
}