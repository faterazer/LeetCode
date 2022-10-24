from typing import List


class Solution:
    def partitionDisjoint(self, nums: List[int]) -> int:
        res = 1
        last_max = cur_max = nums[0]
        for i, e in enumerate(nums):
            if e < last_max:
                res = i + 1
                last_max = cur_max
            else:
                cur_max = max(cur_max, e)
        return res
