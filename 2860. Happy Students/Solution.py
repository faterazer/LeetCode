from itertools import pairwise
from typing import List


class Solution:
    def countWays(self, nums: List[int]) -> int:
        nums.sort()
        res = (nums[0] > 0) + 1
        for i, (a, b) in enumerate(pairwise(nums), 1):
            res += a < i < b
        return res
