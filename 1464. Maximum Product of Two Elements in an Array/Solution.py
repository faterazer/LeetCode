from typing import List


class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        mx1 = mx2 = 0
        for x in nums:
            if x >= mx1:
                mx1, mx2 = x, mx1
            elif x > mx2:
                mx2 = x
        return (mx1 - 1) * (mx2 - 1)
