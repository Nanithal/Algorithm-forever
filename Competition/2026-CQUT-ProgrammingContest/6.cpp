// 大赛第六题箱子下落
// 模拟
#include <iostream>
#include <string>
int n, m;
const int N = 100010;
using namespace std;
string origin[N], after[N];
void solve(int col, int u, int d, int cnt)
{
    for (int i = u; i <= d - cnt; i++)
        after[i][col] = '.';
    for (int i = d - cnt + 1; i <= d; i++)
        after[i][col] = '*';
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> origin[i];
        after[i] = origin[i];
    }
    for (int j = 0; j < m; j++)
    {
        int d = n, cnt = 0;
        for (int i = n; i >= 1; i--)
        {
            if (origin[i][j] == '*')
                ++cnt;
            if (origin[i][j] == '-')
            {
                solve(j, i + 1, d, cnt);
                d = i - 1;
                cnt = 0;
            }
        }
        solve(j, 1, d, cnt);
    }
    for (int i = 1; i <= n; i++)
        cout << after[i] << '\n';
    return 0;
}