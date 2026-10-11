

#include <iostream>
#include <string>
using namespace std;
const int N = 5e4 + 2;
int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int n;
    cin >> n;
    for (int j = 1; j <= n; j++)
    {
        string input;
        bool vis[N] = {false};
        cin >> input;
        for (int i = 0; i < input.size(); i++)
        {
            if (input[i] == '1' || input[i] == 'i' || input[i] == 'I' || input[i] == 'l')
                vis[i] = 1;
        }
        for (int i = 0; i < input.size(); i++)
        {
            if (!vis[i])
                cout << input[i];
        }
        cout << '\n';
    }
    return 0;
}