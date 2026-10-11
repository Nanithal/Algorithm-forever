#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int mountian[N];
list<int> staack[N];
void output(int a)
{
    cout << a << ' ';
    if (!staack[a].empty())
    {
        for (int i : staack[a])
        {
            output(i);
        }
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> mountian[i];
    for (int i = n; i >= 1; i--)
    {
        if (mountian[i])
            staack[mountian[i]].push_back(i);
    }
    for (int i = n; i >= 1; i--)
    {
        if (!mountian[i])
        {
            cout << i << ' ';
            int temp = i;
            if (!staack[temp].empty())
            {
                for (int a : staack[temp])
                {
                    output(a);
                }
            }
        }
    }
    return 0;
}