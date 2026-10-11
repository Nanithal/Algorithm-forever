#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

long long dist2(P a, P b)
{
    long long dx = a.first - b.first;
    long long dy = a.second - b.second;
    return dx * dx + dy * dy;
}

// 判断4个点是否构成正方形
bool isSquare(vector<P> p)
{
    vector<long long> d;
    // 枚举全部6组两点距离平方
    for (int i = 0; i < 4; i++)
    {
        for (int j = i + 1; j < 4; j++)
        {
            d.push_back(dist2(p[i], p[j]));
        }
    }
    sort(d.begin(), d.end());
    // 前4条是边长，后2条对角线
    long long side = d[0];
    long long diag = d[5];
    // 边长不能为0（四点重合/多点重合），对角线=2*边长，前四条相等，后两条相等
    if (side == 0)
        return false;
    if (d[0] == d[1] && d[1] == d[2] && d[2] == d[3] && d[4] == d[5] && diag == 2 * side)
        return true;
    return false;
}

int main()
{
    vector<P> pts(4);
    for (int i = 0; i < 4; i++)
    {
        cin >> pts[i].first >> pts[i].second;
    }
    if (isSquare(pts))
    {
        cout << "wen\n";
        return 0;
    }
    vector<P> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool ok = false;
    for (int i = 0; i < 4; i++)
    {
        for (auto delta : dir)
        {
            vector<P> tmp = pts;
            tmp[i].first += delta.first;
            tmp[i].second += delta.second;
            if (isSquare(tmp))
            {
                ok = true;
                break;
            }
        }
        if (ok)
            break;
    }
    if (ok)
        cout << "hai xing\n";
    else
        cout << "wo jue de bu xing\n";
    return 0;
}