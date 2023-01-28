from typing import List


class Solution:
    def waysToMakeFair(self, nums: List[int]) -> int:
        res = s = 0
        for i, x in enumerate(nums):
            s += -x if i & 1 else x
        for i, x in enumerate(nums):
            s += x if i & 1 else -x
            res += (s == 0)
            s += x if i & 1 else -x
        return res
