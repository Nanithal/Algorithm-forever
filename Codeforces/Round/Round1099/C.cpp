// https://codeforces.com/problemset/problem/2231/C

#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int N = 1e5 + 1;
int t, n, a;
long long ans;
void solve()
{

    cin >> n;
    vector<map<int, int>> num1(n + 1);
    map<int, int> num2;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;

        if (a == 1)
        {
            num1[i][a] = 0;
            num1[i][2] = 1;
            num2[1]++;
            num2[2]++;
        }
        else
        {
            int j = 0;
            while (a != 1)
            {
                num1[i][a] = j++;
                num2[a]++;
                if (a & 1)
                    a += 1;
                else
                    a /= 2;
            }
            num1[i][a] = j;
            num2[a]++;
        }
    }
    for (auto &it : num2)
    {
        if (it.second == n)
        {
            int d = it.first;
            long long temp = 0;
            for (int i = 1; i <= n; i++)
            {
                temp += num1[i][d];
            }
            ans = min(ans, temp);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        ans = 1e18;
        solve();
        cout << ans << '\n';
    }
    return 0;
}