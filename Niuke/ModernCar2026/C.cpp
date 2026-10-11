// 一维差分的二阶形式

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m, l, r;
void solve()
{
    cin >> n >> m;

    // 🔴 坑点1：因为二阶差分会修改到 r + 2 的位置，所以数组大小必须开到 n + 3
    // 使用局部 vector，每次进入 solve 会自动初始化为 0，完美解决多测清空问题
    vector<long long> d2(n + 3, 0);
    for (int i = 1; i <= m; i++)
    {

        cin >> l >> r;
        int len = r - l + 1;
        int mid = (l + r) / 2;

        if (len % 2 == 1)
        {
            // 奇数长度山形，例如 [1, 5]，中点为 3
            d2[l] += 1;
            d2[mid + 1] -= 2;
            d2[r + 2] += 1;
        }
        else
        {
            // 偶数长度山形，例如 [1, 4]，中点为 2
            d2[l] += 1;
            d2[mid + 1] -= 1;
            d2[mid + 2] -= 1;
            d2[r + 2] += 1;
        }
    }

    // 第一次前缀和：从二阶差分还原为一阶差分 d1
    vector<long long> d1(n + 2, 0);
    for (int i = 1; i <= n + 1; i++)
    {
        d1[i] = d1[i - 1] + d2[i];
    }

    // 第二次前缀和：从一阶差分还原为原数组 a
    vector<long long> a(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        a[i] = a[i - 1] + d1[i];
        cout << a[i] << (i == n ? "" : " ");
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}