#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 2e5 + 1;
const int INF = 0x3f3f3f3f;
void solve()
{
	int n, a, num1 = 0, num2 = 0, num3 = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a;
		if (a & 1)
			num1++;
		else if (a % 4 == 0)
			num2++;
		else
			num3++;
	}
	cout << max(num1, max(num2, num3)) << endl;
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
