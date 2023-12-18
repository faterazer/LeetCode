from typing import List


class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        l, r = 0, len(nums) - 2
        while l <= r:
            m = l + ((r - l) >> 1)
            if nums[m] < nums[m + 1]:
                l = m + 1
            else:
                r = m - 1
        return l
