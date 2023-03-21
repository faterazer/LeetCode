from typing import List


class Solution:
    def zeroFilledSubarray(self, nums: List[int]) -> int:
        res = j = 0
        for i in range(len(nums)):
            if nums[i] != 0:
                j = i + 1
            res += i - j + 1
        return res
