#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 2e5 + 1;
int c[N], w[N];
const int INF = 0x3f3f3f3f;
const ll INFF = 0x3f3f3f3f3f3f3f3f;
void solve()
{
    int n, k;
    ll ans = 0;
    cin >> n >> k;
    unordered_map<int, int> cla_num;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i] >> w[i];
        cla_num[c[i]]++;
    }
    vector<pair<int, int>> sa;
    int now = 1, org = 1;
    while (now <= n)
    {
        unordered_map<int, int> saa;
        saa[c[now]]++;
        if (saa[c[now]] == cla_num[c[now]])
        {
            bool vis = 1;
            for (auto &p : saa)
            {
                if (saa[p.first] != cla_num[p.first])
                {
                    vis = 0;
                    break;
                }
            }
            if (vis)
            {
                sa.push_back({org, now});
                org = now + 1;
                now++;
                break;
            }
        }
        now++;
    }
    if (sa.size() < k || sa[sa.size() - 1].second != n)
    {
        cout << -1 << endl;
        return;
    }
    vector<ll> sd;
    ll l = INFF, r = 0;
    for (auto &p : sa)
    {
        ll temp = 0;
        for (int i = p.first; i <= p.second; i++)
            temp += w[i];
        l = min(temp, l);
        r += temp;
        sd.push_back(temp);
    }
    int size = sd.size();
    while (l < r)
    {
        ll mid = l + ((r - l) >> 1);
        int num = 0;
        ll now = 0;
        for (int i = 0; i < size; i++)
        {
            now += sd[i];
            if (now >= mid)
            {
                num++;
                now = 0;
            }
        }
        if (num == k)
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << endl;
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