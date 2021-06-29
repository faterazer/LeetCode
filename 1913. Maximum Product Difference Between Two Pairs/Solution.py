from typing import List


class Solution:
    def maxProductDifference(self, nums: List[int]) -> int:
        mx1 = mn2 = max(nums[0], nums[1])
        mx2 = mn1 = min(nums[0], nums[1])
        for x in nums[2:]:
            if x >= mx1:
                mx2 = mx1
                mx1 = x
            elif x > mx2:
                mx2 = x
            if x <= mn1:
                mn2 = mn1
                mn1 = x
            elif x < mn2:
                mn2 = x
        return mx1 * mx2 - mn1 * mn2
