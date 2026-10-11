#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 1;
int a[N];
unordered_map<ll, pair<int, int>> sa;
pair<int, int> judge(ll x)
{
    int num1 = 0, num2 = -1, idex = 0;
    if (!x)
        return {0, 31};
    while (x)
    {
        if (x & 1)
        {
            num1++;
            if (num2 == -1)
                num2 = idex;
        }
        x >>= 1;
        idex++;
    }
    return {num1, num2};
}
bool com(ll a, ll b)
{
    auto aa = sa[a];
    auto bb = sa[b];
    if (aa.first < bb.first)
        return true;
    if (aa.first == bb.first)
    {
        if (aa.second < bb.second)
            return true;
        if (aa.second == bb.second)
            return a < b;
    }
    return false;
}
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (auto &p : a)
    {
        cin >> p;
        sa[p] = judge(p);
    }
    sort(a.begin(), a.end(), com);
    cout << a[k - 1] << endl;
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