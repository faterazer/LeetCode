from typing import List


class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        res = accum = 0
        seen = {}
        for i, e in enumerate(nums):
            accum += 1 if e else -1
            if accum == 0:
                res = i + 1
            elif accum in seen:
                res = max(res, i - seen[accum])
            else:
                seen[accum] = i
        return res
