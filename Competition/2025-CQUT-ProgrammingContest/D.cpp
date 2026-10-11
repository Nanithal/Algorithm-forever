#include <iostream>
#include <algorithm>
const int N = 10010;
using namespace std;
int ans[N];
int dp[N];
char input[N][N];
int temp = 0;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        input[0][i] = '0';
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> input[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int temp1 = dp[j];
            if (input[i][j] != '0')
            {
                int minn = dp[j - 1];
                dp[j] = min(minn, min(dp[j], temp)) + input[i][j] - '0';
            }
            else
                dp[j] = 0;
            temp = temp1;
            ans[dp[j]]++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        for (int j = i; j <= n; j++)
            sum += ans[j];
        cout << sum << ' ';
    }
    return 0;
}