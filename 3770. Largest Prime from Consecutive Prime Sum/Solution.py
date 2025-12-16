import bisect

MX = 500001
is_prime = [True] * MX
primes = []
for i in range(2, MX):
    if is_prime[i]:
        primes.append(i)
    j = 0
    while j < len(primes) and i * primes[j] < MX:
        is_prime[i * primes[j]] = False
        if i % primes[j] == 0:
            break
        j += 1


prime_sum = 0
candidates = []
for i, p in enumerate(primes):
    prime_sum += p
    if prime_sum < len(is_prime) and is_prime[prime_sum]:
        candidates.append(prime_sum)


class Solution:
    def largestPrime(self, n: int) -> int:
        idx = bisect.bisect_right(candidates, n)
        return candidates[idx - 1] if idx > 0 else 0
