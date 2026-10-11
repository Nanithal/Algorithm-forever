#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
struct monster
{
public:
    ll a, b;
} in[101];
bool com(monster a, monster b)
{
    return a.a < b.a;
}
void solve()
{
    int n, k;
    ll s;
    cin >> n >> k >> s;
    for (int i = 1; i <= n; i++)
        cin >> in[i].a >> in[i].b;
    sort(in + 1, in + n + 1, com);
    for (int i = 1; i <= n; i++)
    {
        if (in[i].a <= s)
            s += in[i].b;
        else
        {
            while (k && s < in[i].a)
            {
                s *= 2;
                k--;
            }
            if (in[i].a <= s)
                s += in[i].b;
            else
                break;
        }
    }
    while (k)
    {
        k--;
        s *= 2;
    }
    cout << s << endl;
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
    return 0;
}