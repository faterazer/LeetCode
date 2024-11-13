from typing import List


class Solution:
    def countFairPairs(self, nums: List[int], lower: int, upper: int) -> int:
        ans = 0
        nums.sort()
        left = right = len(nums)
        for j, x in enumerate(nums):
            while left and nums[left - 1] >= lower - x:
                left -= 1
            while right and nums[right - 1] > upper - x:
                right -= 1
            ans += min(right, j) - min(left, j)
        return ans
