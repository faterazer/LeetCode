from typing import List


class Solution:
    def maxOperations(self, nums: List[int]) -> int:
        s = nums[0] + nums[1]
        for i in range(3, len(nums), 2):
            if nums[i - 1] + nums[i] != s:
                return i // 2
        return len(nums) // 2
