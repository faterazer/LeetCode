from typing import List


class Solution:
    def semiOrderedPermutation(self, nums: List[int]) -> int:
        n = len(nums)
        mn_idx, mx_idx = nums.index(1), nums.index(n)
        return n - mx_idx - 1 + mn_idx - (mn_idx > mx_idx)
