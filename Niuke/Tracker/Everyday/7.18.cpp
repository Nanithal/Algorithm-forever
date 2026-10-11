// 本体的数据量较小，可以采用枚举的方式

#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
ll n, m, a, b, limit, rn, rm, j;
int main()
{
    // 提高输入输出效率
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> a >> b;
    ll ans = 0;
    ll limit = min(n / 2, m);
    for (ll i = 0; i <= limit; i++)
    {
        rn = n - 2 * i;
        rm = m - i;
        j = min(rn, rm / 2);
        ans = max(ans, i * a + j * b);
    }
    cout << ans << "\n";
    return 0;
}