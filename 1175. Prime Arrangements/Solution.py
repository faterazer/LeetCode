import math


class Solution:
    def numPrimeArrangements(self, n: int) -> int:
        # 线性筛（欧拉筛），计算出给定范围内的素数个数
        buff = [True] * (n + 1)
        primes = []
        for i in range(2, len(buff)):
            if buff[i]:
                primes.append(i)
            for p in primes:
                if p * i > n:
                    break
                buff[p * i] = False
                if i % p == 0:
                    break
        return math.factorial(len(primes)) * math.factorial(n - len(primes)) % (10 ** 9 + 7)
