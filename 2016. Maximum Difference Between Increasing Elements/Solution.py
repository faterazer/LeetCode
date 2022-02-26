from typing import List


class Solution:
    def maximumDifference(self, nums: List[int]) -> int:
        res = -1
        minimum = float('inf')
        for e in nums:
            if e > minimum:
                res = max(res, e - minimum)
            else:
                minimum = e
        return res
