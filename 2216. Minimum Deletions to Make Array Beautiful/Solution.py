from typing import List


class Solution:
    def minDeletion(self, nums: List[int]) -> int:
        n, i, j = len(nums), 0, 1
        while j < len(nums):
            while j < len(nums) and nums[j] == nums[i]:
                j += 1
                n -= 1
            i, j = j + 1, j + 2
        return len(nums) - n + 1 if n % 2 == 1 else len(nums) - n
