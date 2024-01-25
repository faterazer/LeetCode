from typing import List


class Solution:
    def sumIndicesWithKSetBits(self, nums: List[int], k: int) -> int:
        return sum(e for i, e in enumerate(nums) if i.bit_count() == k)
