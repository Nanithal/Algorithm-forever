#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
void solve()
{
    ll n;
    map<int, int> save;
    cin >> n;
    bool vis1 = false, vis2 = false;
    ll temp = n;
    while (temp)
    {
        int num = temp % 10;
        save[num] = 1;
        temp /= 10;
    }
    for (auto &p : save)
    {
        if (p.first == 0)
        {
            vis1 = 1;
        }
        else
        {
            if (n % p.first == 0)
                vis1 = 1;
            else
                vis2 = 1;
        }
    }
    if (vis1 && vis2)
        cout << 'H' << endl;
    else if (vis1)
        cout << 'G' << endl;
    else
        cout << 'S' << endl;
    return;
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