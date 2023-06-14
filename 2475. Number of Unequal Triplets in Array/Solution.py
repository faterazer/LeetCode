from collections import Counter
from typing import List


class Solution:
    def unequalTriplets(self, nums: List[int]) -> int:
        res = t = 0
        n = len(nums)
        for v in Counter(nums).values():
            res += t * v * (n - t - v)
            t += v
        return res
