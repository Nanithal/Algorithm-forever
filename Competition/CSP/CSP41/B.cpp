

#include <iostream>
#include <algorithm>
using namespace std;
const int N = 210;
int n, o;
double m, ans;
class tt
{
public:
    double t;
    double a;
    double b;
    double avergae;
} ro1[N], ro2[N];
bool com1(tt w, tt q)
{
    return (w.avergae >= q.avergae);
}
bool com2(tt w, tt q)
{
    return (w.b >= q.b && w.a <= w.a && w.a <= q.b);
}
int main()
{
    ans = 0;
    int size1 = 1, size2 = 1, p1, p2;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> o;
        if (!o)
        {
            cin >> ro1[size1].t;
            ans += ro1[size1].t;
            cin >> ro1[size1].a;
            cin >> ro1[size1].b;
            ro1[size1].avergae = ro1[size1].b / ro1[size1].a;
            size1++;
        }
        else
        {
            cin >> ro2[size2].t;
            ans += ro2[size2].t;
            cin >> ro2[size2].a;
            cin >> ro2[size2].b;
            ro2[size2].avergae = ro2[size2].b / ro2[size2].a;
            size2++;
        }
    }
    ro1[size1].avergae = 0;
    ro2[size2].avergae = 0;
    sort(ro1 + 1, ro1 + size1, com1);
    sort(ro2 + 1, ro2 + size2, com1);
    if (size1 > 1 && size2 > 1)
    {
        for (p1 = p2 = 1; m > 0 && p1 < size1 && p2 < size2;)
        {
            if (m < ro2[p2].a)
            {
                if (p1 == size1)
                    break;
                if (ro1[p1].a >= m)
                {
                    m -= ro1[p1].a;
                    ans -= ro1[p1].b;
                }
                else
                {
                    ans -= m * ro1[p1].avergae;
                    m -= m;
                }
                p1++;
            }
            else
            {
                if (ro1[p1].avergae < ro2[p2].avergae)
                {
                    if (ro1[p1].a >= m)
                    {
                        m -= ro1[p1].a;
                        ans -= ro1[p1].b;
                    }
                    else
                    {
                        m -= m;
                        ans -= m / ro1[p1].a * ro1[p1].b;
                    }
                    p1++;
                }
                else
                {
                    m -= ro2[p2].a;
                    ans -= ro2[p2].b;
                    p2++;
                }
            }
        }
    }
    else
    {
        while (p1 < size1 && m > 0)
        {
            if (ro1[p1].a >= m)
            {
                m -= ro1[p1].a;
                ans -= ro1[p1].b;
            }
            else
            {
                ans -= m * ro1[p1].avergae;
                m -= m;
            }
            p1++;
        }
        while (p2 < size2 && m > 0)
        {
                }
    }
    cout << ans << '\n';
    return 0;
}