#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;
long long a[N], n;
void solve()
{
    int nums1[3] = {0};
    int nums2[10] = {0};
    int ans = 1e7, num = 0;
    bool ok = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] % 9 == 0 && !ok)
            ok = 1;
        else if (num < 2 && a[i] % 3 == 0)
            num++;
        else
        {
            nums1[(a[i] + 2) / 3 * 3 - a[i]]++;
            nums2[(a[i] + 8) / 9 * 9 - a[i]]++;
        }
    }
    if (n == 1)
    {
        ans = (a[1] + 8) / 9 * 9 - a[1];
    }
    else
    {
        if (num >= 2 || ok)
            ans = 0;
        else
        {
            for (int i = 1; i <= 2; i++)
            {
                if (nums2[i])
                    ans = min(ans, i);
            }
            if (num == 1)
            {
                if (nums1[1])
                    ans = min(ans, 1);
                else if (nums1[2])
                    ans = min(ans, 2);
            }
            else
            {
                if (nums1[1] >= 2)
                    ans = min(ans, 2);
                else if (nums1[1] >= 1 && nums1[2] >= 1)
                    ans = min(ans, 3);
                else if (nums1[2] >= 2)
                    ans = min(ans, 4);
            }
        }
    }
    cout << ans << '\n';
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