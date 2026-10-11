// #include <bits/stdc++.h>
// #define endl '\n'
// using namespace std;
// using ll = long long;
// using ull = unsigned long long;

// const int N = 2e5 + 1;
// int ans;
// bool judge(string s)
// {
//     int p = 0, q = s.size() - 1;
//     bool ok = 1;
//     while (p < q)
//     {
//         if (s[p] != s[q])
//         {
//             ok = 0;
//             return ok;
//         }
//         p++;
//         q--;
//     }
//     return ok;
// }
// void pro(string s)
// {
//     string a = "";
//     if (s == "")
//         return;
//     int size = s.size() - 1;
//     if (s[0] != s[size])
//     {
//         char c = s[0];
//         for (int i = 1; i <= size; i++)
//         {
//             if (s[i] != c)
//                 a = a + s[i];
//         }
//         if (judge(a))
//             ans++;
//         c = s[size];
//         a = "";
//         for (int i = 0; i < size; i++)
//         {
//             if (s[i] != c)
//                 a = a + s[i];
//         }
//         if (judge(a))
//             ans++;
//         return;
//     }
//     else
//     {
//         char c = s[0];
//         for (int i = 1; i < size; i++)
//         {
//             if (s[i] != c)
//                 a = a + s[i];
//         }
//         if (judge(a))
//         {
//             ans++;
//             pro(a);
//         }
//         return;
//     }
// }
// void solve()
// {
//     int n;
//     string s;
//     char c;
//     map<char, bool> b;
//     cin >> n >> s;
//     pro(s);
//     cout << ans << endl;
// }
// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     solve();
//     return 0;
// }

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int INF = 0x3f3f3f3f;

bool judge(string s)
{
    int p1 = 0, p2 = s.size() - 1;
    while (p1 < p2)
    {
        if (s[p1] != s[p2])
            return false;
        p1++, p2--;
    }
    return true;
}

void solve()
{
    int n, ans = 0;
    cin >> n;
    string s;
    cin >> s;
    for (char c = 'a'; c <= 'z'; c++)
    {
        string t;
        for (auto &p : s)
        {
            if (p == c)
                continue;
            t.push_back(p);
        }
        if (t != s && judge(t))
            ans++;
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}