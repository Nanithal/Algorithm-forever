#include <iostream>
#include <map>
#include <string>
using namespace std;
int n, Q, opt, sum;
string temp;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> Q;
    sum = n;
    map<string, int> in;
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        in[temp]++;
    }
    for (int i = 1; i <= Q; i++)
    {
        cin >> opt;
        if (opt & 1)
        {
            cin >> temp;
            in[temp]++;
            sum++;
        }
        else
        {
            cout << sum - in.size() << '\n';
            sum = in.size();
        }
    }
    return 0;
}