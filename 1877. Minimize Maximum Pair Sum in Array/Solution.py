from typing import List


class Solution:
    def minPairSum(self, nums: List[int]) -> int:
        nums.sort()
        res = 0
        i, j = 0, len(nums) - 1
        while i < j:
            res = max(res, nums[i] + nums[j])
            i += 1
            j -= 1
        return res
