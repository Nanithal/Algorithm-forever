#include <iostream>
using namespace std;
const int N = 45;
int book[N];
int ans = 0, n, m;
// 深搜代码，时间复杂度为O(2^n),n为40时，时间爆炸
void dfs(int p, int cur)
{
    if (cur > m)
        return;
    if (p > n && cur <= m)
    {
        ans++;
        return;
    }
    dfs(p + 1, cur + book[p]);
    dfs(p + 1, cur);
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> book[i];
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}
// 深搜优化，将书分成两个部分，两个部分进行dfs，并将两部分的cur存起来，
// 然后双重循环将cur1+cur2判断是否超出m，则可以过40