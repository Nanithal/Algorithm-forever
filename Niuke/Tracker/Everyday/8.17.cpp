#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
void solve()
{
    int n, a;
    map<int, int> save;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        save[a]++;
    }
    if (save.size() >= 3)
    {
        cout << "Lie" << endl;
        return;
    }
    if (save.size() == 2)
    {
        int minn = save.begin()->first;
        int maxn = save.rbegin()->first;
        if (maxn - minn == 1 && save.begin()->second == maxn)
            cout << "Other" << endl;
        else
            cout << "Lie" << endl;
        return;
    }
    int num = save.begin()->first;
    if ((num == n - 1) || (n / num >= 2))
        cout << "Other" << endl;
    else
        cout << "Lie" << endl;
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