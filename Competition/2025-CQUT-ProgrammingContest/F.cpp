#include <iostream>
#include <cmath>
long long n, k, sum;
using namespace std;
int main()
{
    sum = pow(2, n * k);
    for (int)
}

// 快速幂计算 a^b mod modu
// long long qpow(long long a, long long b, long long modu)
// {
//     long long res = 1;
//     while (b > 0)
//     {
//         if (b & 1)
//             res = res * a % modu;
//         a = a * a % modu;
//         b >>= 1;
//     }
//     return res;
// }

// // 组合数预处理
// vector<long long> get_comb(int n, long long modu)
// {
//     vector<long long> C(n + 1, 1);
//     for (int i = 1; i <= n; ++i)
//     {
//         C[i] = C[i - 1] * (n - i + 1) % modu * qpow(i, modu - 2, modu) % modu;
//     }
//     return C;
// }

// int main()
// {
//     int n, k;
//     const long long MOD = 1e9 + 7; // 可根据题目要求修改模数
//     cin >> n >> k;

//     vector<long long> C = get_comb(n, MOD);
//     long long ans = 0;

//     for (int m = 0; m <= n; ++m)
//     {
//         long long term = C[m];
//         if (m % 2 == 1)
//             term = (MOD - term) % MOD; // (-1)^m
//         long long pow2 = qpow(2, 1LL * k * (n - m), MOD);
//         term = term * pow2 % MOD;
//         ans = (ans + term) % MOD;
//     }

//     cout << ans << endl;
//     return 0;
// }