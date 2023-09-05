from typing import List


class Solution:
    def minNumber(self, nums1: List[int], nums2: List[int]) -> int:
        for i in range(1, 10):
            if i in nums1 and i in nums2:
                return i
        x, y = min(nums1), min(nums2)
        return min(x * 10 + y, y * 10 + x)
