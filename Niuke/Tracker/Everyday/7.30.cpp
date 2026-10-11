#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
// 暴力枚举法

// 最大回文字符串====中心扩展法
//  void solve1()
//  {
//      string s;
//      cin >> s;
//      int ans = 1;
//      int size = s.size();
//      for (int i = 0; i < size; i++)
//      {
//          int temp = 1;
//          int l = i - 1;
//          int r = i + 1;
//          while (l >= 0 && r < size)
//          {
//              if (s[l] == s[r])
//                  temp += 2;
//              else
//                  break;
//              l--;
//              r++;
//          }
//          ans = max(ans, temp);
//      }
//      for (int i = 0; i < size - 1; i++)
//      {
//          int temp = 0;
//          int l = i;
//          int r = i + 1;
//          while (l >= 0 && r < size)
//          {
//              if (s[l] == s[r])
//                  temp += 2;
//              else
//                  break;
//              l--;
//              r++;
//          }
//          ans = max(ans, temp);
//      }
//      cout << ans << endl;
//  }

// 中心扩展法优化-----二分+哈希
const ull P = 131;     // 常用Base进制数
vector<ull> p, h1, h2; // p为进制幂次，h1为正向哈希，h2为反向哈希
// ull的数据结构等效于自动取模
//  1.获取正向区间[l,r]的哈希值
ull get_h1(int l, int r)
{
    return h1[r] - h1[l - 1] * p[r - l + 1];
}

// 2.获取反向区间[l,r]的哈希值
ull get_h2(int l, int r)
{
    return h2[l] - h2[r + 1] * p[r - l + 1];
}

// 3.O(1)判断区间[l.r]是否为回文串
bool is_palindrom(int l, int r)
{
    return get_h1(l, r) == get_h2(l, r);
}
void solve2()
{
    string s;
    cin >> s;
    int n = s.size();
    s = " " + s; // 下标转换为1-n
    p.assign(n + 2, 1);
    h1.assign(n + 2, 0);
    h2.assign(n + 2, 0);

    // 预处理次方与哈希表
    for (int i = 1; i <= n; i++)
        p[i] = p[i - 1] * P;
    for (int i = 1; i <= n; i++)
        h1[i] = h1[i - 1] * P + s[i];
    for (int i = n; i >= 1; i--)
        h2[i] = h2[i + 1] * P + s[i];
    int max_len = 0;

    // 枚举每一个中心点
    for (int i = 1; i <= n; i++)
    {
        // a.枚举奇数长度回文串
        int l = 1, r = min(i, n - i + 1), best_odd = 1;
        while (l < r)
        {
            int mid = l + ((r - l + 1) >> 1);
            if (is_palindrom(i - mid + 1, i + mid - 1))
            {
                best_odd = mid;
                l = mid;
            }
            else
            {
                r = mid - 1;
            }
        }
        max_len = max(max_len, 2 * best_odd - 1);

        // b.枚举偶数长度回文串
        l = 1;
        r = min(i, n - i);
        int best_even = 0;
        while (l < r)
        {
            int mid = l + ((r - l + 1) >> 1);
            if (is_palindrom(i - mid + 1, i + mid))
            {
                best_even = mid;
                l = mid;
            }
            else
            {
                r = mid - 1;
            }
        }
        max_len = max(max_len, 2 * best_even);
    }
    cout << max_len << endl;
}
// 马拉车算法
void solve3()
{
    string s;
    cin >> s;
    string t = "^";
    for (auto &it : s)
    {
        t += "#";
        t += it;
    }
    t += "#$";
    int n = t.size();    // 2m+3
    vector<int> p(n, 0); // 回文半径数组
    int C = 0, R = 0;    // 当前最右回文串的中心与右边界

    int max_len = 0;      // 最长回文字串的长度
    int center_index = 0; // 最长回文子串在t中的中心位置

    // 遍历处理每个位置
    for (int i = 1; i < n - 1; i++)
    {
        // 利用对称性获取初始半径
        int i_mirror = 2 * C - i;
        if (R > i)
        {
            p[i] = min(R - i, p[i_mirror]);
        }
        else
        {
            p[i] = 1;
        }

        // 尝试向两边扩展（存在哨兵字符在，不会越界）
        while (t[i + p[i]] == t[i - p[i]])
        {
            p[i]++;
        }

        // 如果扩展出了更靠右的边界，更新C和R
        if (i + p[i] > R)
        {
            C = i;
            R = i + p[i];
        }

        // 记录全局最长回文串
        if (p[i] - 1 > max_len)
        {
            max_len = p[i] - 1; // 变换后串的半径减一正好等于原串的回文长度
            center_index = i;
        }
    }

    // 根据中心和长度，还原到原字符串中的最长回文子串
    // int start = (center_index - max_len) / 2;
    // return s.substr(start, max_len);
    cout << max_len << endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve2();
    }
    return 0;
}