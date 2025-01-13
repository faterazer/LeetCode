from itertools import accumulate
from typing import List


class Solution:
    def waysToSplitArray(self, nums: List[int]) -> int:
        total = sum(nums)
        return sum(pre_sum >= total - pre_sum for pre_sum in accumulate(nums[:-1]))
