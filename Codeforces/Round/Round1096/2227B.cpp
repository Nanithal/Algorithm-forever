// https://codeforces.com/problemset/problem/2227/B

#include <iostream>
using namespace std;
const int N = 2e5 + 1;
char a[N];
int n, num1, num2;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        num1 = num2 = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if (a[i] == '(')
                num1++;
            else
                num2++;
        }
        if (num1 != num2)
            cout << "NO" << '\n';
        else
            cout << "YES" << '\n';
    }
}