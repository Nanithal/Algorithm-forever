#include <iostream>

using namespace std;

int n, a;
int state_num[4];
long long ans = 1e7;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        state_num[a]++;
    }
    for (int base = 0; base <= 3; base++)
    {
        long long temp = 0;
        for (int i = 0; i <= 3; i++)
        {
            if (i == base)
                continue;
            temp += state_num[i] * (((i - base) % 4 + 4) % 4);
        }
        if ((temp + base) % 4)
            temp += 4 - ((temp + base) % 4);
        ans = min(ans, temp);
    }
    cout << ans << '\n';
    return 0;
}