#include <iostream>
#include <string>
using namespace std;
string in;
int ans, n;
void solve()
{
    cin >> n;
    cin >> in;
    ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (in[i] == '#')
        {
            int temp = 0;
            while (i < n && in[i] == '#')
            {
                i++;
                temp++;
            }
            ans = max(ans, temp);
        }
    }
    cout << (ans + 1) / 2 << '\n';
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
}