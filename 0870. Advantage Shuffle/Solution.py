from typing import List


class Solution:
    def advantageCount(self, nums1: List[int], nums2: List[int]) -> List[int]:
        nums1.sort(reverse=True)
        buff = sorted([(e, i) for i, e in enumerate(nums2)], key=lambda x: x[0], reverse=True)
        lo, hi = 0, len(nums1) - 1
        res = [0] * len(nums1)
        for e, idx in buff:
            if nums1[lo] > e:
                res[idx] = nums1[lo]
                lo += 1
            else:
                res[idx] = nums1[hi]
                hi -= 1
        return res
