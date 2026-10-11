#include <iostream>
using namespace std;
const int N = 1e7;
int three[N];
int n, m, ans = 0;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        three[a * 100 + b * 10 + c] = 1;
    }
    for (int i = 1; i <= n - 3; i++)
    {
        for (int j = i + 1; j <= n - 2; j++)
        {
            for (int k = j + 1; k <= n - 1; k++)
            {
                for (int l = k + 1; l <= n; l++)
                {
                    if (!three[i * 100 + j * 10 + k])
                        continue;
                    if (!three[i * 100 + j * 10 + l])
                        continue;
                    if (!three[i * 100 + k * 10 + l])
                        continue;
                    if (!three[j * 100 + k * 10 + l])
                        continue;
                    ans++;
                }
            }
        }
    }
    cout << ans;
    return 0;
}