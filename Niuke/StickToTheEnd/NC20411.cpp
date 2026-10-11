
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// p[n][X] 表示 n 个盘子从 X 柱子出发最终到达的柱子
int P[35][3];
// g[n][X] 表示 n 个盘子从 X 柱子出发完全移走的总步数
long long g[35][3];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    if (!(cin >> n))
        return 0;
    vector<string> prior(6);
    for (int i = 0; i < 6; i++)
    {
        cin >> prior[i];
    }
    for (int X = 0; X < 3; X++)
    {
        for (int i = 0; i < 6; i++)
        {
            if (prior[i][0] - 'A' == X)
            {
                P[1][X] = prior[i][1] - 'A';
                g[1][X] = 1;
                break;
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        for (int X = 0; X < 3; X++)
        {
            int Y = P[i - 1][X];
            int Z = 3 - X - Y;
            g[i][X] = g[i - 1][X] + 1 + g[i - 1][Y];
            P[i][X] = P[i - 1][Y];
        }
    }
    cout << g[n][0] << '\n';

    return 0;
}