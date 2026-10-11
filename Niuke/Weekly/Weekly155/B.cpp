#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int a;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll ans = 0, x;
    cin >> a;
    for (int i = 0; i <= a; i++)
    {
        for (int j = 0; j <= a; j++)
        {
            for (int k = 0; k <= a; k++)
            {
                cin >> x;
                int temp = 0;
                if (i == j && j == k)
                    temp++;
                if (i == j && k + j == a)
                    temp++;
                if (i == k && k + j == a)
                    temp++;
                if (j == k && i + j == a)
                    temp++;
                for (int p = 1; p <= temp; p++)
                {
                    ans += x;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}