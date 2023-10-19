from collections import Counter
from typing import List


class Solution:
    def tupleSameProduct(self, nums: List[int]) -> int:
        n = len(nums)
        cnt = Counter([nums[i] * nums[j] for i in range(n) for j in range(i + 1, n)])
        res = 0
        for v in cnt.values():
            res += v * (v - 1) * 4
        return res
