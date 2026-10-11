// https://codeforces.com/problemset/problem/2227/C

#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
const int N = 2e5 + 1;
long long a[N];
long long t, n, ans, num = 0;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        int num[4] = {0};
        deque<int> b;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if (a[i] % 6 == 0)
            {
                b.push_front(a[i]);
            }
            else if (a[i] == 2 || a[i] == 3)
                num[a[i]]++;
            else
                b.push_back(a[i]);
        }
        if (num[2] >= 1 && num[3] >= 1)
        {
            if (num[2] > num[3])
            {
                for (int i = 1; i <= num[2] - num[3]; i++)
                    b.push_back(2);
                num[2] = num[3];
            }
            else if (num[3] > num[2])
            {
                for (int i = 1; i <= num[3] - num[2]; i++)
                    b.push_back(3);
                num[3] = num[2];
            }
            for (int i = 1; i <= num[2]; i++)
            {
                b.push_front(2);
                b.push_back(3);
            }
        }
        for (auto it : b)
            cout << it << ' ';
        cout << '\n';
    }
    return false;
}