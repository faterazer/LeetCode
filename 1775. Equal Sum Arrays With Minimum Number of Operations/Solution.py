from typing import List


class Solution:
    def minOperations(self, nums1: List[int], nums2: List[int]) -> int:
        m, n = len(nums1), len(nums2)
        if max(m, n) > 6 * min(m, n):
            return -1

        sum1, sum2 = sum(nums1), sum(nums2)
        if sum1 == sum2:
            return 0
        if sum1 > sum2:
            sum1, sum2 = sum2, sum1
            nums2, nums1 = nums1, nums2

        cnt1, cnt2 = [0] * 7, [0] * 7
        for e in nums1:
            cnt1[e] += 1
        for e in nums2:
            cnt2[e] += 1

        diff = abs(sum1 - sum2)
        res = 0
        for i in range(1, 7):
            while cnt1[i] > 0:
                res += 1
                diff -= 6 - i
                if diff <= 0:
                    return res
                cnt1[i] -= 1
            while cnt2[7 - i] > 0:
                res += 1
                diff -= 6 - i
                if diff <= 0:
                    return res
                cnt2[7 - i] -= 1
        return res
