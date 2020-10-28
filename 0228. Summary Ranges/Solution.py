from typing import List


class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        ret = []
        i = 0
        while i < len(nums):
            j = i + 1
            while j < len(nums) and nums[j] == nums[j - 1] + 1:
                j += 1
            ret.append(str(nums[i]))
            if i != j - 1:
                ret[-1] += '->' + str(nums[j - 1])
            i = j
        return ret
