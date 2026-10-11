// // https://atcoder.jp/contests/abc457/tasks/abc457_e

#include <iostream>
#include <map>
#include <vector>

using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 200005;
vector<int> l[MAXN];
vector<int> r[MAXN];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M, Q;
    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int ll, rr;
        cin >> ll >> rr;
        l[ll].push_back(rr);
        r[rr].push_back(ll);
    }
    for (int i = 1; i <= N; ++i)
    {
        if (!l[i].empty())
            sort(l[i].begin(), l[i].end());
        if (!r[i].empty())
            sort(r[i].begin(), r[i].end());
    }
    cin >> Q;
    while (Q--)
    {
        int Sq, Tq;
        cin >> Sq >> Tq;
        if (l[Sq].empty() || r[Tq].empty())
        {
            cout << "No" << "\n";
            continue;
        }
        auto it1 = upper_bound(l[Sq].begin(), l[Sq].end(), Tq);
        if (it1 == l[Sq].begin())
        {
            cout << "No" << "\n";
            continue;
        }
        int max_Ra = *(--it1);
        auto it2 = lower_bound(r[Tq].begin(), r[Tq].end(), Sq);
        if (it2 == r[Tq].end())
        {
            cout << "No" << "\n";
            continue;
        }
        int min_Lb = *it2;
        if (max_Ra >= min_Lb - 1 && !(max_Ra == Tq && min_Lb == Sq && it1 == l[Sq].begin() && it2 == --r[Tq].end()))
        {
            cout << "Yes" << "\n";
        }
        else
        {
            cout << "No" << "\n";
        }
    }

    return 0;
}