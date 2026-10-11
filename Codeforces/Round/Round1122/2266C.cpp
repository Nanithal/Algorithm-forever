#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 2e5 + 1;
int sum[N];
const int INF = 0x3f3f3f3f;
void solve()
{
	int n, ans = INF, now = 0;
	string s;
	cin >> n;
	cin >> s;
	s = ' ' + s;
	vector<int> sa;
	for (int i = 1; i <= n; i++)
	{
		if (s[i] == '1')
			sa.push_back(i);
		sum[i] = sum[i - 1] + s[i] - '0';
	}
	if (s[1] == '1')
	{
		cout << n - 1 - sum[n] + sum[1] << endl;
		return;
	}
	sa.push_back(n + 1);
	sum[n + 1] = sum[n] + 1;
	for (auto &p : sa)
	{
		ans = min(ans, now + n - p - sum[n] + sum[p]);
		now++;
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
