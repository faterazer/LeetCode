from typing import List


class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        i, n = 0, len(nums)
        while i < n:
            if 0 < nums[i] <= n and nums[i] != nums[nums[i] - 1]:
                nums[nums[i] - 1], nums[i] = nums[i], nums[nums[i] - 1]
            else:
                i += 1
        for i in range(n):
            if nums[i] != i + 1:
                return i + 1
        return n + 1
