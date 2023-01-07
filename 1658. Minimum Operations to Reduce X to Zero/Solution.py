from typing import List


class Solution:
    def minOperations(self, nums: List[int], x: int) -> int:
        total = sum(nums)

        left = window_sum = 0
        res = float("inf")
        for right in range(len(nums)):
            window_sum += nums[right]
            while left <= right and total - window_sum < x:
                window_sum -= nums[left]
                left += 1
            if total - window_sum == x:
                res = min(res, len(nums) - right + left - 1)
        return -1 if res == float("inf") else res
