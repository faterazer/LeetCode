from typing import List


class Solution:
    def findLengthOfLCIS(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        maxLen = curLen = 1
        for i in range(1, len(nums)):
            if nums[i] > nums[i - 1]:
                curLen += 1
            else:
                maxLen = max(maxLen, curLen)
                curLen = 1
        return max(maxLen, curLen)
