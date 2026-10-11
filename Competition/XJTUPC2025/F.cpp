// https://codeforces.com/gym/105937/problem/F

// 交互题

#include <bits/stdc++.h>

using namespace std;

long long t, n, mid, l = 1, r, judge;
long long L[17];

void init()
{
    for (int i = 1; i <= 16; i++)
    {
        L[i] = 4 * L[i - 1] + 1;
    }
}
int main()
{
    init();
    cin >> t;
    while (t--)
    {
        l = 1;
        r = 2;
        cin >> n;
        if (n <= 4)
        {
            cout << "! " << min(2 * L[1], n) << '\n';
            cout.flush();
        }
        else
        {
            while (L[r] <= n && r <= 16)
            {
                r++;
            }
            r--;
            while (l < r)
            {
                mid = l + ((r - l + 1) >> 1);
                cout << "? " << L[mid] << '\n';
                cout.flush();
                cin >> judge;
                if (judge == 1)
                    r = mid - 1;
                else
                    l = mid;
            }
            cout << "! " << min(n, 2 * L[l]) << '\n';
            cout.flush();
        }
    }
    return 0;
}