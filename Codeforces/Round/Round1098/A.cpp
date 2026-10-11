#include <bits/stdc++.h>
int n, a;
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int ans = 0, num1 = 0, num2 = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a;
            if (a == 0)
                ans++;
            else if (a == 1)
                num1++;
            else
                num2++;
        }
        int minn = min(num1, num2);
        ans += minn;
        num1 -= minn;
        num2 -= minn;
        if (num1)
            ans += num1 / 3;
        if (num2)
            ans += num2 / 3;
        cout << ans << '\n';
    }
    return 0;
}