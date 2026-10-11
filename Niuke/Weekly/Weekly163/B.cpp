#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int INF = 0x3f3f3f3f;

string trans(int x)
{
    string res;
    while (x)
    {
        int temp = x % 2;
        x /= 2;
        res = (char)(temp + '0') + res;
    }
    int rest = 4 - res.size();
    for (int i = 1; i <= rest; i++)
        res = '0' + res;
    return res;
}

void solve()
{
    string s;
    int k;
    cin >> s >> k;

    bool ok = 1;
    for (auto &c : s)
    {
        if (c != '0')
            ok = 0;
    }
    if (ok)
    {
        cout << "YES\n";
        return;
    }

    int size = s.size();
    if (size < k / 4 + 1)
    {
        cout << "NO\n";
        return;
    }
    size--;
    int up = (k + 1) / 4;
    for (int i = size; i >= size - up + 1; i--)
    {
        if (s[i] != '0')
        {
            cout << "NO\n";
            return;
        }
    }
    int rest = k - up * 4;
    int x;
    if (x >= 'a')
        x = s[size - up] - 'a' + 10;
    else if (x >= 'A')
        x = s[size - up] - 'A' + 10;
    else
        x = s[size - up] - '0';
    string sd = trans(x);
    int now = 3;
    while (rest)
    {
        if (sd[now] != '0')
        {
            cout << "NO\n";
            return;
        }
        now--;
        rest--;
    }
    cout << "YES\n";
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