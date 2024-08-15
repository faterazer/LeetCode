from typing import List


class Solution:
    def isArraySpecial(self, nums: List[int], queries: List[List[int]]) -> List[bool]:
        last_same = [0] * len(nums)
        for i in range(1, len(nums)):
            last_same[i] = i if nums[i - 1] % 2 == nums[i] % 2 else last_same[i - 1]
        return [last_same[b] <= a for a, b in queries]
