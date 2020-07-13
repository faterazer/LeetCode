from collections import Counter
from typing import List


class Solution:
    def intersect_MK1(self, nums1: List[int], nums2: List[int]) -> List[int]:
        '''
        哈希映射
        '''
        if len(nums1) > len(nums2):
            return self.intersect_MK1(nums2, nums1)
        
        hash_map = {}
        ret = []
        for num in nums1:
            hash_map[num] = hash_map.get(num, 0) + 1
        for num in nums2:
            if hash_map.get(num, 0) > 0:
                ret.append(num)
                hash_map[num] -= 1
        return ret

    def intersect_MK2(self, nums1: List[int], nums2: List[int]) -> List[int]:
        '''
        排序
        '''
        nums1.sort()
        nums2.sort()
        i, j = 0, 0
        ret = []
        while i < len(nums1) and j < len(nums2):
            if nums1[i] == nums2[j]:
                ret.append(nums1[i])
                i += 1
                j += 1
            elif nums1[i] < nums2[j]:
                i += 1
            else:
                j += 1
        return ret

    def intersect_MK3(self, nums1: List[int], nums2: List[int]) -> List[int]:
        return (Counter(nums1) & Counter(nums2)).elements()
