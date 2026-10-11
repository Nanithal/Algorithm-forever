#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;
int n, a[N], k;
void solve()
{
    cin >> n >> k;
    vector<int> nums(n + 1, 0);
    bool ok = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        nums[a[i]]++;
    }
    sort(a + 1, a + n + 1);
    if (a[1] == a[n])
    {
        if (n & 1)
        {
            cout << "NO" << '\n';
            return;
        }
        else
        {
            cout << "YES" << '\n';
            return;
        }
    }
    else
    {
        for (int i = n; i >= 1;)
        {
            if (!(nums[a[i]] & 1))
            {
                cout << "YES" << '\n';
                return;
            }
            else
            {
                if (a[i] - a[i - nums[a[i]]] <= k && i - nums[a[i]] >= 1)
                {
                    cout << "YES" << '\n';
                    return;
                }
                i = i - nums[a[i]];
            }
        }
    }
    cout << "NO" << '\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}