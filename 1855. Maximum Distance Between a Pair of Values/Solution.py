class Solution:
    def maxDistance(self, nums1: list[int], nums2: list[int]) -> int:
        result = i = j = 0
        while i < len(nums1) and j < len(nums2):
            if nums1[i] > nums2[j]:
                i += 1
            else:
                result = max(result, j - i)
                j += 1
        return result
