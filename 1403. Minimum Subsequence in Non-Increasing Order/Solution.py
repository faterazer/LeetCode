from typing import List


class Solution:
    def minSubsequence(self, nums: List[int]) -> List[int]:
        sum1, sum2 = 0, sum(nums)
        res = []
        for x in sorted(nums, reverse=True):
            res.append(x)
            sum1 += x
            sum2 -= x
            if sum1 > sum2:
                break
        return res
