#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1;
long long n, q, l, r;
long long b[N];
long long get(long long l, long long r)
{
	long long now = l, res = 0;
	while (now <= r)
	{
		if (b[now] == 0)
		{
			res++;
			now++;
		}
		else
		{
			long long sum = b[now];
			long long i = now + 2;
			if (i <= r)
			{
				long long orig = now;
				while (i <= r)
				{
					if (b[i - 1] == 0)
					{
						res++;
						now = i;
						break;
					}
					else
					{
						if (b[i] != 0)
						{
							if (b[i] == b[i - 2])
							{
								res++;
								now = i + 1;
								break;
							}
							else
							{
								sum = sum ^ b[i];
								now = i + 1;
								i += 2;
							}
						}
						else
						{
							res++;
							now = i + 1;
							break;
						}
					}
					bool ok = 0;
					for (int j = orig; j <= i - 2; j++)
					{
						if (sum == b[j])
						{
							res++;
							now = i - 1;
							ok = 1;
							break;
						}
					}
					if (ok)
						break;
					if (sum == 0)
					{
						res++;
						now = i - 1;
						break;
					}
				}
			}
			else
				now++;
		}
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> b[i];
	for (int i = 1; i <= q; i++)
	{
		cin >> l >> r;
		cout << get(l, r) << '\n';
	}
	return 0;
}
