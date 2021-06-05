from typing import List


class Solution:
    def minOperations(self, nums: List[int]) -> int:
        res = prev = 0
        for x in nums:
            if x <= prev:
                prev += 1
                res += prev - x
            else:
                prev = x
        return res
