import math
from typing import List


class Solution:
    def minimumSum(self, nums: List[int]) -> int:
        n = len(nums)
        pre_min = [nums[0]]
        for i in range(1, n - 2):
            pre_min.append(min(pre_min[i - 1], nums[i]))

        res, suf_min = math.inf, nums[-1]
        for i in range(n - 2, 0, -1):
            if pre_min[i - 1] < nums[i] > suf_min:
                res = min(res, pre_min[i - 1] + nums[i] + suf_min)
            suf_min = min(suf_min, nums[i])
        return -1 if res == math.inf else res
