from typing import List


class Solution:
    def minimumAddedInteger(self, nums1: List[int], nums2: List[int]) -> int:
        nums1.sort()
        nums2.sort()
        for i in (2, 1):
            d = nums2[0] - nums1[i]
            it = iter(nums1)
            if all(x - d in it for x in nums2):
                return d
        return nums2[0] - nums1[0]
