import collections
from typing import List


class Solution:
    # Hash
    # Time complexity: O(n)
    # Space complexity: O(1)
    def findLHS_MK1(self, nums: List[int]) -> int:
        ret = 0
        counter = collections.Counter(nums)
        for key in counter:
            if key + 1 in counter:
                ret = max(ret, counter[key] + counter[key + 1])
        return ret

    # Sort
    # Time complexity: O(nlgn)
    # Space complexity: O(1)
    def findLHS_MK2(self, nums: List[int]) -> int:
        nums.sort()
        beg, new_beg, ret = 0, 0, 0
        for i in range(1, len(nums)):
            if nums[i] - nums[beg] > 1:
                beg = new_beg
            if nums[i] != nums[i - 1]:
                new_beg = i
            if nums[i] - nums[beg] == 1:
                ret = max(ret, i - beg + 1)
        return ret
