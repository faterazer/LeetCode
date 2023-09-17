from typing import List


class Solution:
    def rob(self, nums: List[int]) -> int:
        def robRange(nums: List[int], beg: int, end: int) -> int:
            pre1 = pre2 = 0
            for i in range(beg, end):
                tmp = max(pre1 + nums[i], pre2)
                pre1 = pre2
                pre2 = tmp
            return pre2

        if len(nums) == 1:
            return nums[0]
        return max(robRange(nums, 0, len(nums) - 1), robRange(nums, 1, len(nums)))
