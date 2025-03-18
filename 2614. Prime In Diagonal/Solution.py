is_primes = [True] * 4000001
primes = []
for i in range(2, len(is_primes)):
    if is_primes[i]:
        primes.append(i)
    for p in primes:
        if p * i >= len(is_primes):
            break
        is_primes[p * i] = False
        if p % i == 0:
            break
primes = set(primes)


class Solution:
    def diagonalPrime(self, nums: list[list[int]]) -> int:
        n = len(nums)
        ans = 0
        for i in range(n):
            if nums[i][i] in primes:
                ans = max(ans, nums[i][i])
            if nums[i][n - 1 - i] in primes:
                ans = max(ans, nums[i][n - 1 - i])
        return ans
