#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 2e5 + 1;
const int INF = 0x3f3f3f3f;
void solve()
{
	int n, k, ans = 0;
	cin >> n >> k;
	string s;
	cin >> s;
	s = ' ' + s;
	int up = n / k;
	for (int i = 0; i < up; i++)
	{
		bool ok = 1;
		for (int j = 1; j <= k; j++)
		{
			if (s[i * k + j] == '0')
			{
				ok = 0;
				break;
			}
		}
		if (ok)
			ans++;
	}
	cout << ans << endl;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
