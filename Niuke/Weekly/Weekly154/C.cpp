#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
string a;
int n, k;
void solve()
{
    map<char, int> num;
    vector<int> release(5, 0); // 上下左右
    cin >> n >> k;
    cin >> a;
    for (int i = 0; i < n; i++)
    {
        num[a[i]]++;
    }
    if (num['U'] >= num['D'])
    {
        release[2] += min(num['D'], k);
        k -= min(num['D'], k);
    }
    else
    {
        release[1] += min(num['U'], k);
        k -= min(num['U'], k);
    }
    if (num['L'] >= num['R'])
    {
        release[4] += min(num['R'], k);
        k -= min(num['R'], k);
    }
    else
    {
        release[3] += min(num['L'], k);
        k -= min(num['L'], k);
    }
    if (k)
    {
        if (!release[1])
        {
            release[1] += min(num['U'], k);
            k -= min(num['U'], k);
        }
        if (!release[2])
        {
            release[2] += min(num['D'], k);
            k -= min(num['D'], k);
        }
        if (!release[3])
        {
            release[3] += min(num['L'], k);
            k -= min(num['L'], k);
        }
        if (!release[4])
        {
            release[4] += min(num['R'], k);
            k -= min(num['R'], k);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 'U')
        {
            if (release[1])
            {
                release[1]--;
                continue;
            }
            cout << a[i];
        }
        if (a[i] == 'D')
        {
            if (release[2])
            {
                release[2]--;
                continue;
            }
            cout << a[i];
        }
        if (a[i] == 'L')
        {
            if (release[3])
            {
                release[3]--;
                continue;
            }
            cout << a[i];
        }
        if (a[i] == 'R')
        {
            if (release[4])
            {
                release[4]--;
                continue;
            }
            cout << a[i];
        }
    }
    cout << endl;
    return;
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
}
