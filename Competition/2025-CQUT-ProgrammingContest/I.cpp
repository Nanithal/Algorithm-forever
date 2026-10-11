#include <iostream>
const int N = 100010;
int product[N];
using namespace std;
int find(int n)
{
    int ans = -1, now = n, num = 0;
    while (now >= 1)
    {
        now -= product[now];
        num++;
    }
    if (now < 0)
        return ans;
    return num;
}
int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int n;
        cin >> n;
        for (int j = 1; j <= n; j++)
            cin >> product[j];
        cout << find(n) << endl;
    }
}