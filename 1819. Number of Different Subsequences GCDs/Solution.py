from math import gcd
from typing import List


class Solution:
    def countDifferentSubsequenceGCDs(self, nums: List[int]) -> int:
        nums = set(nums)
        res, max_val = len(nums), max(nums) + 1
        for i in range(1, max_val // 3 + 1):
            if i in nums:
                continue
            g = 0
            for j in range(i * 2, max_val, i):
                if j in nums:
                    g = gcd(g, j)
                if g == i:
                    break
            if g == i:
                res += 1
        return res
