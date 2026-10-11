#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
void solve()
{
    int d, n, temp, num = 0;
    string s;
    cin >> n >> d;
    temp = d;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '+')
        {
            d = (d + 1) % 10;
        }
        else
        {
            d = (d + 9) % 10;
        }
        if (d == temp)
            num++;
    }
    cout << d << ' ' << num;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}