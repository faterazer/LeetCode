#include <math.h>
#include <memory.h>

int numPrimeArrangements(int n)
{
    // 线性筛（欧拉筛），计算出给定范围内的素数个数
    int buff[n + 1], primes[25], len = 0;
    for (int i = 2; i <= n; i++)
        buff[i] = 1;
    for (int i = 2; i <= n; i++) {
        if (buff[i])
            primes[len++] = i;
        for (int j = 0; j < len && primes[j] * i <= n; j++) {
            buff[primes[j] * i] = 0;
            if (i % primes[j] == 0)
                break;
        }
    }
    long long res = 1;
    const int MOD = 1e9 + 7;
    int m = n - len;    // 给定范围内有 len 个素数，m 个合数，res = len! + m!
    for (int i = 2; i <= len; i++)
        res = (res * i) % MOD;
    for (int i = 2; i <= m; i++)
        res = (res * i) % MOD;
    return res;
}
