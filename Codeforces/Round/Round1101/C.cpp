#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, x, s;
string u;
void solve()
{
    cin >> n >> x >> s >> u;
    vector<int> size_num(x + 1, 0);
    int a = 1, b = 1, ans = 0;
    int size = u.size();
    for (int i = 0; i < size; i++)
    {
        char identity = u[i];
        if (identity == 'A')
        {
            if (a <= b && size_num[a] < s)
            {
                ans++;
                size_num[a]++;
                if (size_num[a] == s)
                    a++;
            }
            else if (b <= x)
            {
                size_num[b] = 1;
                ans++;
                b++;
            }
        }
        else if (identity == 'E')
        {
            if (a <= b && a <= x && size_num[a] > 0 && size_num[a] < s)
            {
                size_num[a]++;
                ans++;
                if (size_num[a] == s)
                {
                    a++;
                }
            }
        }
        else
        {
            if (b <= x && !size_num[b])
            {
                ans++;
                size_num[b] = 1;
                b++;
            }
        }
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}