from typing import List


class Solution:
    def alternatingSubarray(self, nums: List[int]) -> int:
        res = dp = -1
        for i in range(1, len(nums)):
            if dp >= 2 and nums[i] == nums[i - 2]:
                dp += 1
            else:
                dp = 2 if nums[i] == nums[i - 1] + 1 else -1
            res = max(res, dp)
        return res
