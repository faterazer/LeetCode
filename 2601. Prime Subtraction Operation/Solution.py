import bisect
from typing import List

MAX_LEN = 1001
is_prime = [True] * MAX_LEN
primes = []
for i in range(2, MAX_LEN):
    if is_prime[i]:
        primes.append(i)
    j = 0
    while j < len(primes) and primes[j] * i < MAX_LEN:
        is_prime[primes[j] * i] = False
        if i % primes[j] == 0:
            break
        j += 1


class Solution:
    def primeSubOperation(self, nums: List[int]) -> bool:
        for i in range(len(nums) - 2, -1, -1):
            if nums[i] < nums[i + 1]:
                continue
            idx = bisect.bisect_right(primes, nums[i] - nums[i + 1])
            if idx == len(primes) or primes[idx] >= nums[i]:
                return False
            nums[i] -= primes[idx]
        return True
