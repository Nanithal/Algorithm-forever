#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
void solve()
{
    string s;
    char c = 'o';
    cin >> s;
    for (int i = 0; i < 5; i++)
    {
        if (isdigit(s[i]))
            c = s[i];
    }
    if (c != 'o')
        cout << c;
    else
        cout << -1 << endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}