#include <iostream>
#include <vector>
using namespace std;
long long n, l, temp, loca;
long long k, sd;
int main()
{
    cin >> n >> k;
    vector<vector<long long>> a(n + 1);
    vector<long long> b;
    vector<long long> c;
    for (int i = 0; i < n; i++)
    {
        cin >> l;
        b.push_back(l);
        for (int j = 1; j <= l; j++)
        {
            cin >> temp;
            a[i].push_back(temp);
        }
    }
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        c.push_back(temp);
        c[i] *= b[i];
        if (sd < k)
        {
            loca = i;
            sd += c[i];
        }
    }
    sd -= c[loca];
    if (sd > 0)
        cout << a[loca][(k - sd - 1) % (b[loca])] << '\n';
    else
        cout << a[loca][(k - 1) % (b[loca])] << '\n';
    return 0;
}