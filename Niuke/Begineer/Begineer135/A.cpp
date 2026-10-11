#include <bits/stdc++.h>
using namespace std;
int n, a, b;
int main()
{
    int ans;
    cin >> n >> a >> b;
    int s = min(a, b);
    int m = max(a, b);
    if (n <= s)
    {
        ans = s;
    }
    else if (n >= s + m)
    {
        ans = 0;
    }
    else
    {
        ans = m - (n - s);
    }
    cout << ans << '\n';
    return 0;
}