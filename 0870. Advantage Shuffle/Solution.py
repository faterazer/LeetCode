from typing import List


class Solution:
    def advantageCount(self, nums1: List[int], nums2: List[int]) -> List[int]:
        n = len(nums1)
        nums1.sort()
        buff = sorted(zip(nums2, range(n)), key=lambda x: x[0], reverse=True)
        res = [0] * n
        lo, hi = 0, n - 1
        for e, i in buff:
            if nums1[hi] > e:
                res[i] = nums1[hi]
                hi -= 1
            else:
                res[i] = nums1[lo]
                lo += 1
        return res
