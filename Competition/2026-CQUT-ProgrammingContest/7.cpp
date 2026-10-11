// 大赛第七题 通配回文
// 符合要求的字符串长度非奇则偶
// 每次从前往后遍历，以a[i]为中心点或者a[i]、a[i+1]为中心点，依次左边界和右边界向左/向右
// 扩张1再接着判断
// 则对奇数和偶数来说，各遍历一次字符串
#include <iostream>
#include <string>
using namespace std;
bool check(char a, char b)
{
    if ((a == b) || a == '?' || b == '?')
        return true;
    return false;
}
int main()
{
    long long ans = 0;
    string S;
    cin >> S;
    for (int i = 0; i < S.size(); i++)
    {
        int L = i, R = i;
        while (check(S[L], S[R]))
        {
            ++ans;
            --L;
            ++R;
            if (L < 0 || R > S.size() - 1)
                break;
        }
    }
    for (int i = 0; i < S.size() - 1; i++)
    {
        int L = i, R = i + 1;
        while (check(S[L], S[R]))
        {
            ++ans;
            --L;
            ++R;
            if (L < 0 || R >= S.size())
                break;
        }
    }
    cout << ans << '\n';
    return 0;
}