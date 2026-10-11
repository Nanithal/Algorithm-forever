#include <iostream>
const long long N = 100010;
long long solider[N], improve[N];
long long n, S, L, l, r = 1e8, ans;
using namespace std;
bool check()
{
    long long sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (ans * improve[i] + solider[i] >= L)
            sum += ans * improve[i] + solider[i];
    }
    return sum >= S;
}
int main()
{
    cin >> n >> S >> L;
    for (int i = 1; i <= n; i++)
        cin >> solider[i];
    for (int i = 1; i <= n; i++)
        cin >> improve[i];
    while (l < r)
    {
        ans = l + ((r - l) >> 1);
        if (check())
            r = ans;
        else
            l = ans + 1;
    }
    cout << l;
}