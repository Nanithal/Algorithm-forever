#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;

int n;

void solve()
{
    string a, b;
    vector<int> l1odd, l1even;
    vector<int> l2odd, l2even;
    cin >> n;
    cin >> a >> b;
    a = " " + a;
    b = " " + b;
    if (a == b)
    {
        cout << 0 << endl;
        return;
    }
    if (a != b && n < 3)
    {
        cout << -1 << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == '1' && b[i] == '0')
        {
            if (i & 1)
                l1odd.push_back(i);
            else
                l1even.push_back(i);
        }
        else if (a[i] == '0' && b[i] == '1')
        {
            if (i & 1)
                l2odd.push_back(i);
            else
                l2even.push_back(i);
        }
    }

    if ((l1odd.size() == l2odd.size()) && (l1even.size() == l2even.size()))
    {
        ll ans = 0;
        for (int i = 0; i < l1odd.size(); i++)
        {
            ans += abs(l2odd[i] - l1odd[i]) / 2;
        }
        for (int i = 0; i < l1even.size(); i++)
        {
            ans += abs(l2even[i] - l1even[i]) / 2;
        }
        cout << ans << endl;
        return;
    }
    else
    {
        cout << -1 << endl;
        return;
    }
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