from typing import List


class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        i, prod, res = 0, 1, 0
        for j, e in enumerate(nums):
            prod *= e
            while i <= j and prod >= k:
                prod //= nums[i]
                i += 1
            res += j - i + 1
        return res
