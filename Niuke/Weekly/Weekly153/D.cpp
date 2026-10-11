#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s, t;
    cin >> n >> s >> t;

    vector<int> A, B;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0' && t[i] == '1')
        {
            A.push_back(i + 1); // 下标从 1 开始
        }
        else if (s[i] == '1' && t[i] == '0')
        {
            B.push_back(i + 1);
        }
    }

    int k = A.size();

    if (k == 0)
    {
        cout << 0 << '\n';
        return 0;
    }

    vector<int> seq;

    for (int i = 0; i < k; i++)
    {
        seq.push_back(A[i]);
        seq.push_back(B[i]);
    }

    cout << 2 * k + 1 << '\n';

    for (int x : seq)
    {
        cout << x << '\n';
    }

    // 最后再操作一次第一个位置
    cout << seq[0] << '\n';

    return 0;
}