from typing import List


class Solution:
    def findMaxK(self, nums: List[int]) -> int:
        res, seen = -1, set()
        for x in nums:
            if -x in seen:
                res = max(res, abs(x))
            seen.add(x)
        return res
