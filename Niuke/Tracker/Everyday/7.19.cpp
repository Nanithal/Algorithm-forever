#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
string n, save;
int judge, temp;
vector<string> ans;
bool com(string a, string b)
{
    if (a.size() < b.size())
        return true;
    if (a.size() == b.size())
        return a < b;
    return false;
}
void simualate(char c)
{
    judge = static_cast<int>(c - '0');
    if (judge & 1)
    {
        save = c + save;
    }
    else
    {
        if (save.empty())
        {
            save = c;
            return;
        }
        temp = static_cast<int>(save.back() - '0');
        if (temp & 1)
        {
            save = c + save;
        }
        else
        {
            ans.push_back(save);
            save = c;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int size = n.size();
    for (int i = size - 1; i >= 0; i--)
    {
        simualate(n[i]);
    }
    ans.push_back(save);
    sort(ans.begin(), ans.end(), com);
    for (auto &x : ans)
        cout << x << '\n';
    return 0;
}