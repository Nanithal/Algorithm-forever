// #include <iostream>
// #include <string>

// using namespace std;

// void solve()
// {
//     int sizes;
//     cin >> sizes;
//     string s;
//     cin >> s;
//     int cnt = 0;
//     for (int j = 0; j < sizes - 1; ++j)
//     {
//         if (s[j] != s[j + 1])
//             cnt++;
//     }
//     if (s == "1111")
//         cout << 2 << '\n';
//     else if (s == "0111")
//         cout << 1 << '\n';
//     else if (s == "1011")
//         cout << 1 << '\n';
//     else if (s == "1101")
//         cout << 1 << '\n';
//     else if (s == "1110")
//         cout << 1 << '\n';
//     else if (s == "1100")
//         cout << 2 << '\n';
//     else if (s == "0011")
//         cout << 2 << '\n';
//     else if (s == "1010")
//         cout << 0 << '\n';
//     else if (s == "0101")
//         cout << 0 << '\n';
//     else if (s == "0110")
//         cout << 2 << '\n';
//     else if (s == "1001")
//         cout << 2 << '\n';
//     else if (s == "0001")
//         cout << 1 << '\n';
//     else if (s == "0010")
//         cout << 1 << '\n';
//     else if (s == "0100")
//         cout << 1 << '\n';
//     else if (s == "1000")
//         cout << 1 << '\n';
//     else if (s == "0000")
//         cout << 2 << '\n';
//     else
//     {
//         if (cnt == 0)
//             cout << 2 << '\n';
//         else if (cnt == 1)
//             cout << 1 << '\n';
//         else if (cnt == 2)
//             cout << 1 << '\n';
//         else
//             cout << 0 << '\n';
//     }
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int t = 1;
//     cin >> t;
//     while (t--)
//         solve();
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    string s;
    cin >> n;
    cin >> s;
    int cur = 0;
    for (int i = 1; i < n; i++)
    {
        cur += s[i] != s[i - 1];
    }
    if (cur >= 3)
    {
        cout << 0 << "\n";
    }
    else if (cur == 0 || s == "1001" || s == "0110" || s == "0011" || s == "1100")
    {
        cout << 2 << "\n";
    }
    else
    {
        cout << 1 << "\n";
    }
}
int main()
{
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
// 64 位输出请用 printf("%lld")
