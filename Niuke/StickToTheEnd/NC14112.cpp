#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
int n;
string input;
void solve()
{
    cin >> n;
    int num = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> input;
        if (input[0] == 'b' && input[1] == 'n' && input[2] == 'u' && input[3] == '1')
        {
            num++;
        }
    }
    cout << num << '\n';
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