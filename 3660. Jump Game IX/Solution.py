import math
from itertools import accumulate


class Solution:
    def maxValue(self, nums: list[int]) -> list[int]:
        n = len(nums)
        pre_max = list(accumulate(nums, max))

        suf_min = math.inf
        for i in range(n - 1, -1, -1):
            if pre_max[i] > suf_min:
                pre_max[i] = pre_max[i + 1]
            suf_min = min(suf_min, nums[i])
        return pre_max
