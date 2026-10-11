#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
void solve()
{
    int b, vis = 0;
    vector<int> v, a;
    for (int i = 1; i <= 3; i++)
    {
        cin >> b;
        v.push_back(b);
    }
    for (int i = 1; i <= 3; i++)
    {
        cin >> b;
        a.push_back(b);
    }
    sort(v.begin(), v.end());
    sort(a.begin(), a.end());
    for (int i = 0; i <= 2; i++)
    {
        for (int j = 0; j < a.size(); j++)
        {
            if (a[j] > v[i])
            {
                vis++;
                a.erase(a.begin() + j);
                break;
            }
        }
    }
    if (vis >= 2)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
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