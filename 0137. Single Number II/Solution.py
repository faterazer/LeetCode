from typing import List


class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        a = b = 0
        for x in nums:
            b = ~a & (b ^ x)
            a = ~b & (a ^ x)
        return b
