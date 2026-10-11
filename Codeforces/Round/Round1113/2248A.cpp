#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
void solve()
{
    string s;
    cin >> s;
    int num1, num2;
    num1 = num2 = 1;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '0' && num1)
        {
            num1--;
            continue;
        }
        if (s[i] == '1' && num2)
        {
            num2--;
            continue;
        }
        cout << s[i];
    }
    cout << endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}