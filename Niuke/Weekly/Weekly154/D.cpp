#include <bits/stdc++.h>
#define endl '\n'
using ll = long long;
using namespace std;
int n, q, l, r, num;
string a;
void solve()
{
    cin >> n >> q;
    vector<bool> judge(n, false);
    cin >> a;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != a[(i + 1) % n])
            judge[i] = true;
        if (judge[i])
            num++;
    }
    for (int i = 1; i <= q; i++)
    {
        cin >> l >> r;
        if (l <= r)
        {
            if (!l && r == n - 1)
            {
                cout << num << endl;
                continue;
            }
            judge[(l - 1 + n) % n] = !judge[(l - 1 + n) % n];
            if (judge[(l - 1 + n) % n])
                num++;
            else
                num--;
            judge[r] = !judge[r];
            if (judge[r])
                num++;
            else
                num--;
        }
        if (l > r)
        {
            judge[l - 1] = !judge[l - 1];
            if (judge[l - 1])
                num++;
            else
                num--;
            judge[r] = !judge[r];
            if (judge[r])
                num++;
            else
                num--;
        }
        cout << num << endl;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--)
    {
        solve();
    }
}