from itertools import pairwise
from math import inf


class Solution:
    def maxSumTrionic(self, nums: list[int]) -> int | float:
        ans = f1 = f2 = f3 = -inf
        for x, y in pairwise(nums):
            f3 = max(f2, f3) + y if x < y else -inf
            f2 = max(f1, f2) + y if x > y else -inf
            f1 = max(f1, x) + y if x < y else -inf
            ans = max(ans, f3)
        return ans
