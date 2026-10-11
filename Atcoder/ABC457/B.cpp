#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, x, y;
    cin >> n;
    vector<vector<int>> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int l;
        cin >> l;
        for (int j = 1; j <= l; j++)
        {
            int d;
            cin >> d;
            a[i].push_back(d);
        }
    }
    cin >> x >> y;
    cout << a[x][y - 1] << '\n';
    return 0;
}