from tkinter import W
from typing import List


class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        res = [-1, -1]
        l, r = 0, len(nums)
        while l < r:
            m = l + ((r - l) >> 1)
            if nums[m] < target:
                l = m + 1
            else:
                r = m
        if l >= len(nums) or nums[l] != target:
            return res
        else:
            res[0] = l
        r = len(nums)
        while l < r:
            m = l + ((r - l) >> 1)
            if nums[m] <= target:
                l = m + 1
            else:
                r = m
        res[1] = l - 1
        return res
