#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e9 / 2 + 5;
void solve()
{
    string s;
    cin >> s;
    map<char, bool> save;
    int size = s.size();
    for (int i = 0; i < size;)
    {
        char c = s[i];
        cout << c;
        while (i < size && s[i] == c)
        {
            i++;
        }
    }
    cout << endl;
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