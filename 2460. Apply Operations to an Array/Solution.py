from typing import List


class Solution:
    def applyOperations(self, nums: List[int]) -> List[int]:
        j, n = 0, len(nums)
        for i in range(n):
            if i + 1 < n and nums[i] == nums[i + 1]:
                nums[i] *= 2
                nums[i + 1] = 0
            if nums[i]:
                nums[i], nums[j] = nums[j], nums[i]
                j += 1
        return nums
