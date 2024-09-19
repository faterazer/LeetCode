from itertools import pairwise


class Solution:
    def longestContinuousSubstring(self, s: str) -> int:
        res = cnt = 1
        for a, b in pairwise(map(ord, s)):
            cnt = cnt + 1 if a + 1 == b else 1
            res = max(res, cnt)
        return res
