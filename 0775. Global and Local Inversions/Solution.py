from typing import List


class Solution:
    def isIdealPermutation_MK1(self, nums: List[int]) -> bool:
        cmax = 0
        for i, e in enumerate(nums[:-2]):
            cmax = max(cmax, e)
            if cmax > nums[i + 2]:
                return False
        return True

    def isIdealPermutation_MK2(self, nums: List[int]) -> bool:
        return all(abs(i - e) <= 1 for i, e in enumerate(nums))
