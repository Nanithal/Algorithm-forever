#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
class card
{
public:
    int v;
    int id;
};
bool com(card a, card b)
{
    return a.v < b.v;
}
void solve()
{
    int a1, a2, b1, b2, ans = 0;
    vector<pair<int, int>> a;
    vector<pair<int, int>> b;
    cin >> a1 >> a2 >> b1 >> b2;
    a.push_back({a1, a2});
    a.push_back({a2, a1});
    b.push_back({b1, b2});
    b.push_back({b2, b1});
    for (auto &p : a)
    {
        for (auto &q : b)
        {
            int A_win = 0, B_win = 0;
            if (p.first > q.first)
                A_win++;
            else if (p.first < q.first)
                B_win++;
            if (p.second > q.second)
                A_win++;
            else if (p.second < q.second)
                B_win++;
            if (A_win > B_win)
                ans++;
        }
    }
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}