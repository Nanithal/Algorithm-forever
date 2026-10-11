#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 2e5 + 1;
const int INF = 0x3f3f3f3f;
void solve()
{
	ll a, b, c;
	cin >> a >> b >> c;
	int turn = 1, nums = 0;
	while (c)
	{
		if (nums == 2)
			break;
		if (turn & 1)
		{
			if (a >= b)
			{
				a += c;
				c = 0;
				nums = 0;
			}
			else
			{
				if (2 * (b - a) <= c)
				{
					a += c;
					c = 0;
					nums = 0;
				}
				else
					nums++;
			}
		}
		else
		{
			if (a > b)
			{
				ll temp = a - b;
				b += min(c, temp);
				c -= min(temp, c);
				nums = 0;
			}
			else
				nums++;
		}
		turn++;
	}
	cout << abs(a - b) << endl;
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
