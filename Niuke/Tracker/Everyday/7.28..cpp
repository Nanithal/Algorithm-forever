#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MAXN = 1e5 + 5;
int a[MAXN];
int ans[MAXN];
int n, q;

multiset<int> left_set;
multiset<int> right_set;
void balance(int k)
{
    int target_left = (k + 1) / 2;

    while (left_set.size() > target_left)
    {
        auto it = prev(left_set.end());
        right_set.insert(*it);
        left_set.erase(it);
    }
    while (left_set.size() < target_left && !right_set.empty())
    {
        auto it = right_set.begin();
        left_set.insert(*it);
        right_set.erase(it);
    }
}
void insert_val(int x, int k)
{
    if (left_set.empty() || x <= *left_set.rbegin())
    {
        left_set.insert(x);
    }
    else
    {
        right_set.insert(x);
    }
    balance(k);
}
void erase_val(int x, int k)
{
    auto it = left_set.find(x);
    if (it != left_set.end())
    {
        left_set.erase(it);
    }
    else
    {
        it = right_set.find(x);
        if (it != right_set.end())
        {
            right_set.erase(it);
        }
    }
    balance(k);
}
void solve()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    vector<pair<int, int>> queries(q);
    int k = 0;
    for (int i = 0; i < q; i++)
    {
        cin >> queries[i].first >> queries[i].second;
    }
    k = queries[0].second - queries[0].first + 1;
    for (int i = 1; i <= k; i++)
    {
        insert_val(a[i], k);
    }
    ans[1] = *left_set.rbegin();
    for (int l = 2; l <= n - k + 1; l++)
    {
        int remove_elem = a[l - 1];
        int add_elem = a[l + k - 1];
        erase_val(remove_elem, k);
        insert_val(add_elem, k);
        ans[l] = *left_set.rbegin();
    }
    for (int i = 0; i < q; i++)
    {
        int l = queries[i].first;
        cout << ans[l] << endl;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}