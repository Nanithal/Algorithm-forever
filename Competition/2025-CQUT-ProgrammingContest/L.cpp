#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
char input[N][N];
int pre[N][N]; // 二维前缀和数组
int num[N];    // num[k] = 边长为k的全1正方形数量

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); // 加速输入输出（n=2010必备）

    int n;
    cin >> n;

    // 1. 正确读入矩阵（无多余getchar，从1开始索引方便前缀和）
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> input[i][j];
        }
    }

    // 2. 计算二维前缀和 O(n²)
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + (input[i][j] - '0');
        }
    }

    // 3. 枚举所有边长k的正方形
    for (int k = 1; k <= n; k++)
    {                            // 边长k
        int max_pos = n - k + 1; // 左上角最大坐标
        for (int i = 1; i <= max_pos; i++)
        {
            for (int j = 1; j <= max_pos; j++)
            {
                // 正方形右下角坐标
                int x2 = i + k - 1;
                int y2 = j + k - 1;
                // 计算正方形内1的总数
                int sum = pre[x2][y2] - pre[i - 1][y2] - pre[x2][j - 1] + pre[i - 1][j - 1];
                // 和为k² → 全1正方形
                if (sum == k * k)
                {
                    num[k]++;
                }
            }
        }
    }

    // 4. 输出结果
    for (int i = 1; i <= n; i++)
    {
        cout << num[i] << " ";
    }
    return 0;
}