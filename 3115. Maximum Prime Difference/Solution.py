from typing import List


class Solution:
    def __init__(self) -> None:
        is_prime = [True] * 101
        primes = []
        for i in range(2, 101):
            if is_prime[i]:
                primes.append(i)
            for p in primes:
                q = p * i
                if q > 100:
                    break
                is_prime[q] = False
                if i % p == 0:
                    break
        self.primes = set(primes)

    def maximumPrimeDifference(self, nums: List[int]) -> int:
        i, j = 0, len(nums) - 1
        while nums[i] not in self.primes:
            i += 1
        while nums[j] not in self.primes:
            j -= 1
        return j - i
