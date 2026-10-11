#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int n;
vector<int> a;
vector<int> dp;

vector<int> lf;
vector<int> rt;

void Solve()
{
    cin >> n;
    a.resize(n);
    for (auto &x : a)
    {
        cin >> x;
    }
    lf.assign(n, -1);
    rt.assign(n, n);
    dp.assign(n + 1, -1);
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i - 1; j > -1; j--)
        {
            if (gcd(a[i], a[j]) > 1)
            {
                lf[i] = j;
                break;
            }
        }
        for (int j = i + 1; j < n; j++)
        {
            if (gcd(a[i], a[j]) > 1)
            {
                rt[i] = j;
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int mini = i;
        for (int j = i - 1; j > -1; j--)
        {
            if (rt[j] >= i)
            {
                mini = min(mini, lf[j]);
            }
            if (mini >= j && dp[j] != -1)
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    cout << dp[n];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Solve();
}