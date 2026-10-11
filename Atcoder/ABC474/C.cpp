#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;
bool iff[N];
int a[N];
int num[N];
void solve()
{
    int n, q, b;
    cin >> n >> q;
    vector<int> res;
    vector<int> sa;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= q; i++)
    {
        cin >> b;
        num[b] = i;
        sa.push_back(b);
        iff[b] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!iff[a[i]])
            res.push_back(a[i]);
    }
    for (int i = 0; i < sa.size(); i++)
    {
        if (i == num[sa[i]] - 1)
            res.push_back(sa[i]);
    }
    for (auto &p : res)
        cout << p << ' ';
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