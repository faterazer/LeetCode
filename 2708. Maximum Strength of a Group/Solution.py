from typing import List


class Solution:
    def maxStrength(self, nums: List[int]) -> int:
        mn = mx = nums[0]
        for x in nums[1:]:
            mn, mx = min(mn, x, mn * x, mx * x), max(mx, x, mn * x, mx * x)
        return mx
