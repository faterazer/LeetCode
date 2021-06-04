from typing import List


class Solution:
    def arraySign(self, nums: List[int]) -> int:
        res = 1
        for x in nums:
            if not x:
                return 0
            elif x < 0:
                res *= -1
        return res
