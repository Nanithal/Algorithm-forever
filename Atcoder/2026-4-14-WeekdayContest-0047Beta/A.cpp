//
//

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N];
int main()
{
    int n, k, ans = 0;
    cin >> n >> k;
    cin >> a[1];
    for (int i = 2; i <= n; i++)
    {
        cin >> a[i];
        if (fabs(a[i] - a[i - 1]) >= k)
            ans++;
    }
    cout << ans << '\n';
    return 0;
}