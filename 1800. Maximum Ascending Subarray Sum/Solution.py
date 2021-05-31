from typing import List


class Solution:
    def maxAscendingSum(self, nums: List[int]) -> int:
        max_sum = cur = nums[0]
        for i in range(1, len(nums)):
            if nums[i] <= nums[i - 1]:
                max_sum = max(max_sum, cur)
                cur = 0
            cur += nums[i]
        return max(max_sum, cur)
