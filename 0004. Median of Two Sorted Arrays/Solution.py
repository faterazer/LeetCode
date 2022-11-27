from typing import List


class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        m, n = len(nums1), len(nums2)
        if m > n:
            return self.findMedianSortedArrays(nums2, nums1)

        lo, hi = 0, m
        median1 = median2 = 0
        while lo <= hi:
            i = (lo + hi) // 2
            j = (m + n + 1) // 2 - i

            nums1_i1 = float("-inf") if i == 0 else nums1[i - 1]
            nums1_i2 = float("inf") if i == m else nums1[i]
            nums2_j1 = float("-inf") if j == 0 else nums2[j - 1]
            nums2_j2 = float("inf") if j == n else nums2[j]

            if nums1_i1 <= nums2_j2:
                median1, median2 = max(nums1_i1, nums2_j1), min(nums1_i2, nums2_j2)
                lo = i + 1
            else:
                hi = i - 1
        return median1 if (m + n) % 2 == 1 else (median1 + median2) / 2
