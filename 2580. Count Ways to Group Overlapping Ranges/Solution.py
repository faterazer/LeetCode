from typing import List


class Solution:
    def countWays(self, ranges: List[List[int]]) -> int:
        MOD = 10**9 + 7
        ranges.sort(key=lambda x: x[0])
        res, max_right = 1, -1
        for l, r in ranges:
            if l > max_right:
                res = res * 2 % MOD
            max_right = max(max_right, r)
        return res
