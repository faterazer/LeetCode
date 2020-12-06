class Solution:
    def countPrimes_MK1(self, n: int) -> int:
        '''
        埃氏筛
        '''
        if n < 2:
            return 0
        is_prime = [True] * n
        is_prime[0] = is_prime[1] = False
        for i in range(2, int(n ** 0.5) + 1):
            if is_prime[i]:
                is_prime[i * i:n:i] = [False] * len(is_prime[i * i:n:i])
        return is_prime.count(True)

    def countPrimes_MK2(self, n: int) -> int:
        '''
        欧拉筛（线性筛）
        '''
        if n < 2:
            return 0
        is_prime = [True] * n
        primes = []
        for i in range(2, n):
            if is_prime[i]:
                primes.append(i)
            j = 0
            while j < len(primes) and i * primes[j] < n:
                is_prime[i * primes[j]] = False
                if i % primes[j] == 0:
                    break;
                j += 1
        return len(primes)
