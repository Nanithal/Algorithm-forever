#include <iostream>
#include <queue>
using namespace std;
int n, num1, num2, ans, temp1, temp2;
string a, b;
void solve()
{
    priority_queue<int> pr1;
    priority_queue<int> pr2;
    cin >> n;
    ans = num1 = num2 = 0;
    cin >> a >> b;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == '1' && b[i] == '0')
        {
            num1++;
            pr1.push(i + 1);
        }
        else if (a[i] == '0' && b[i] == '1')
        {
            num2++;
            pr2.push(i + 1);
        }
    }
    ans = 3 * num1;
    cout << ans << endl;
    while (pr1.size())
    {
        int temp1 = pr1.top();
        int temp2 = pr2.top();
        pr1.pop();
        pr2.pop();
        cout << temp1 << endl
             << temp2 << endl
             << temp1 << endl;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}