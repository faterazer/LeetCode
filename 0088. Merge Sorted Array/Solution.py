from typing import List


class Solution:
    def merge_MK1(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        合并后排序
        """
        nums1[:] = sorted(nums1[:m] + nums2)

    def merge_MK2(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        '''
        双指针/从前往后
        '''
        nums1_copy = nums1[:m]
        i, j, k = 0, 0, 0
        while i < m and j < n:
            if nums1_copy[i] <= nums2[j]:
                nums1[k] = nums1_copy[i]
                i += 1
            else:
                nums1[k] = nums2[j]
                j += 1
            k += 1
        if i < m:
            nums1[k:] = nums1_copy[i:m]
        else:
            nums1[k:] = nums2[j:n]

    def merge_MK3(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        '''
        双指针/从后往前
        '''
        i, j, k = m - 1, n - 1, m + n - 1
        while i >= 0 and j >= 0:
            if nums1[i] >= nums2[j]:
                nums1[k] = nums1[i]
                i -= 1
            else:
                nums1[k] = nums2[j]
                j -= 1
            k -= 1
        nums1[:j+1] = nums2[:j+1]
