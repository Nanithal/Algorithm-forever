#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int INF = 0x3f3f3f3f;
const int N = 1 << 20 + 1;
bool exits[N];
void solve()
{
    int n, b;
    ll sum = 0;
    cin >> n >> b;
    vector<int> a(n + 1);
    vector<int> num(b + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        int v = 0;
        for (char &c : s)
            v = (v << 1) | (c - '0');
        a[i] = v;
        exits[v] = true;
    }
    for (int i = 1; i <= n; i++)
    {
        int x = a[i];
        for (int j = 0; j < b; j++)
        {
            int y = x ^ (1 << j);
            if (exits[y] && x > y)
            {
                sum++;
                num[b - j]++;
            }
        }
    }
    cout << sum << endl;
    for (int i = 1; i <= b; i++)
        cout << num[i] << ' ';
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