// 二分答案
// #include <bits/stdc++.h>
// #define endl '\n'
// using namespace std;

// int n;
// string s;
// string t;

// void solve()
// {
//     long long total_ans = 0;
//     cin >> s;
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> t;
//         int l = 1, r = min(s.size(), t.size());
//         int max_k = 0;
//         while (l <= r)
//         {
//             int mid = l + (r - l) / 2;
//             string prefix = s.substr(0, mid);
//             if (t.find(prefix) != string::npos)
//             {
//                 max_k = mid;
//                 l = mid + 1;
//             }
//             else
//             {
//                 r = mid - 1;
//             }
//         }
//         total_ans += max_k;
//     }

//     cout << total_ans << endl;
// }

// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     solve();
//     return 0;
// }

// KMP算法
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 预处理计算nxt数组
vector<int> getnxt(const string &s)
{
    int n = s.length();
    vector<int> nxt(n, 0);
    for (int i = 1; i < n; i++)
    {
        int j = nxt[i - 1];
        while (j > 0 && s[i] != s[j])
            j = nxt[j - 1];
        if (s[i] == s[j])
            j++;
        nxt[i] = j;
    }
    return nxt;
}

// KMP匹配，寻找最大长度
int getMax(const string &s, const string &t, const vector<int> &nxt)
{
    int n = t.length();
    int m = s.length();
    int j = 0;
    int max_k = 0;
    for (int i = 0; i < n; i++)
    {
        while (j > 0 && t[i] != s[j])
            j = nxt[j - 1];
        if (t[i] == s[j])
            j++;
        max_k = max(max_k, j);
        if (max_k == m)
            return m;
    }
    return max_k;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long ans = 0;
    string s;
    if (!(cin >> s))
        return 0;
    int n;
    cin >> n;
    vector<int> nxt = getnxt(s);
    for (int i = 0; i < n; i++)
    {
        string t;
        cin >> t;
        ans += getMax(s, t, nxt);
    }
    cout << ans << '\n';
    return 0;
}