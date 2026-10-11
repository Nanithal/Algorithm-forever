#include <bits/stdc++.h>
using namespace std;
long long a, n, b, c, ans, num, temp;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> a >> n;
        cin >> b >> c;
        ans = a;
        temp = a;
        while (a)
        {
            a /= 10;
            num++;
        }
    }
    return 0;
}