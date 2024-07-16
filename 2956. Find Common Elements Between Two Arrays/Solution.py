from typing import List


class Solution:
    def findIntersectionValues(self, nums1: List[int], nums2: List[int]) -> List[int]:
        set1, set2 = set(nums1), set(nums2)
        return [sum(e in set2 for e in nums1), sum(e in set1 for e in nums2)]
