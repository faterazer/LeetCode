from typing import List


class Solution:
    def countPairs(self, nums: List[int], target: int) -> int:
        nums.sort()
        left, right, res = 0, len(nums) - 1, 0
        while left < right:
            if nums[left] + nums[right] < target:
                res += right - left
                left += 1
            else:
                right -= 1
        return res
