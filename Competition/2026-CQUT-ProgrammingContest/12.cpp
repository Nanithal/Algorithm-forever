// 大赛第12题  优惠购物
// 首先不管如何，为实现最小代价购买商品，需先购买小价格的商品，则sort排序
// 对于一开始不买任何优惠券，第i个商品购买最多优惠(i-1)元钱(不出现负数购买商品)，
// 则最多总优惠：0+1+2+...+n-1元钱
// 对于一开始若购买t张优惠券，在购买商品送优惠券的基础上,每个商品最多再减t元钱(不出现负数)，
// 则总的最多再优惠n*t元钱，额外花费w*t元钱
// 基于上述，当n<=w时，那么则无需买优惠券
// 当n>w时，则研究如何使总支出最小
// 令b[i]为第i个商品在原有的优惠券基础上花费价钱(>=0)，此时购买商品所送的优惠券效果已减去
// 那么第i个商品额外优惠后购买商品所需即为max(0,b[i]-t)(不能为负数)
// 那么总支出式子即为：w*t+(累加，i从1到n)max(0,b[i]-t);
// 则后式子总结果即为b[i]中大于t个数
// 分析这个式子，t+1时，后式子减小，前式子增大w，此时总的减小，直到后式子减小为w，此后总结果再增加
// 那么即b[i]中大于t个数为w时，总结果最小
// 将b[i]sort，那么得到t=b[n-w];

#include <iostream>
#include <algorithm>
const int N = 1e5 + 10;
int product[N], product1[N], n, w;
long long ans = 0;
using namespace std;
int main()
{
    cin >> n >> w;
    for (int i = 1; i <= n; i++)
        cin >> product[i];
    sort(product + 1, product + n + 1);
    if (n <= w)
    {
        for (int i = 1; i <= n; i++)
        {
            if (product[i] - i + 1 >= 0)
                ans += product[i] - i + 1;
        }
    }
    else
    {
        for (int i = 1; i <= n; i++)
            product1[i] = max(0, product[i] - i + 1);
        sort(product1 + 1, product1 + n + 1);
        int t = product1[n - w];
        ans += w * t;
        for (int i = 1; i <= n; i++)
        {
            if (product1[i] - t >= 0)
                ans += product1[i] - t;
        }
    }
    cout << ans << '\n';
    return 0;
}
