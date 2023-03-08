from typing import List


class Solution:
    def movesToMakeZigzag(self, nums: List[int]) -> int:
        s = [0, 0]
        for i, e in enumerate(nums):
            left = float("inf") if i == 0 else nums[i - 1]
            right = float("inf") if i == len(nums) - 1 else nums[i + 1]
            s[i % 2] += max(e - min(left, right) + 1, 0)
        return min(s)
