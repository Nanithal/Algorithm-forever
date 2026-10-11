#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 2e5 + 1;
const int INF = 0x3f3f3f3f;
void solve()
{
	int n, ans = -INF;
	cin >> n;
	for (int i = 1; i <= 3; i++)
	{
		int a;
		cin >> a;
		ans = max(ans, n - a);
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
