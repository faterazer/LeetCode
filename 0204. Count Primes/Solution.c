#include <memory.h>
#include <stdbool.h>
#include <stdlib.h>

// 埃氏筛
int countPrimes_MK1(int n)
{
    if (n < 2)
        return 0;
    int cnt = 0;
    bool is_prime[n];
    memset(is_prime, true, sizeof(bool) * n);
    for (int i = 2; i < n; i++) {
        if (is_prime[i]) {
            cnt++;
            if (i <= n / i)
                for (int j = i * i; j < n; j += i)
                    is_prime[j] = false;
        }
    }
    return cnt;
}

// 欧拉筛（线性筛）
int countPrimes_MK2(int n)
{
    if (n < 2)
        return 0;
    bool is_prime[n];
    memset(is_prime, true, sizeof(bool) * n);
    int primes[n / 2], len = 0;
    for (int i = 2; i < n; i++) {
        if (is_prime[i])
            primes[len++] = i;
        for (int j = 0; j < len && i * primes[j] < n; j++) {
            is_prime[i * primes[j]] = 0;
            if (i % primes[j] == 0)
                break;
        }
    }
    return len;
}
