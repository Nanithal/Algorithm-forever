// 贪心 + 构造

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 2e5 + 1;
int a[N];
const int INF = 0x3f3f3f3f;
void solve()
{
	int n, min_loc = INF, max_loc = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] == 1)
		{
			min_loc = min(min_loc, i);
			max_loc = max(max_loc, i);
		}
	}
	for (int i = 1; i < min(min_loc, n); i++)
	{
		if (a[i] == -1)
		{
			a[i] = 1;
			break;
		}
	}
	for (int i = n; i > max_loc; i--)
	{
		if (a[i] == -1)
		{
			a[i] = 1;
			break;
		}
	}
	for (int i = 1; i <= n; i++)
		cout << max(a[i], 0) << ' ';
	cout << endl;
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
