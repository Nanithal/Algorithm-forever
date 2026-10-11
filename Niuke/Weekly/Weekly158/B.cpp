#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char, int> save;
    bool ok = 0;
    for (int i = 0; i < n; i++)
    {
        save[s[i]]++;
        if (save[s[i]] == 3 && !ok)
        {
            cout << i + 1 << endl;
            ok = 1;
        }
    }
    if (!ok)
        cout << -1 << endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}