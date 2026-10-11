#include <bits/stdc++.h>
using namespace std;
const int N = 6001;
int a[N], n;
bool check(int x)
{
    vector<bool> is_valid(n + 1, false);
    vector<int> min_val(n + 1, 0), max_val(n + 1, 0);
    for (int i = 1; i <= n - x + 1; i++)
    {
        int mn = a[i], mx = a[i];
        bool has_duplicate = false;
        vector<bool> visited(n + 1, false);

        for (int k = 0; k < x; k++)
        {
            int val = a[i + k];
            if (visited[val])
            {
                has_duplicate = true;
                break;
            }
            visited[val] = true;
            mn = min(mn, val);
            mx = max(mx, val);
        }
        if (!has_duplicate && (mx - mn == x - 1))
        {
            is_valid[i] = true;
            min_val[i] = mn;
            max_val[i] = mx;
        }
    }
    for (int i = 1; i <= n - 2 * x + 1; i++)
    {
        if (!is_valid[i])
            continue;
        for (int j = i + x; j <= n - x + 1; j++)
        {
            if (!is_valid[j])
                continue;
            if (max_val[i] < min_val[j] || max_val[j] < min_val[i])
            {
                int total_min = min(min_val[i], min_val[j]);
                int total_max = max(max_val[i], max_val[j]);

                if (total_max - total_min == 2 * x - 1)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

void solve()
{
    int sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    if (sum == n)
    {
        cout << 0 << '\n';
        return;
    }
    else
    {
        int l = 1, r = n / 2;
        while (l < r)
        {
            int mid = l + ((r - l + 1) >> 1);
            if (check(mid))
            {
                l = mid;
            }
            else
            {
                r = mid - 1;
            }
        }
        if (check(l))
            cout << l << '\n';
        else
            cout << 0 << '\n';
    }
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
    return 0;
}