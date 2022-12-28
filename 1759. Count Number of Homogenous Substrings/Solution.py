import itertools


class Solution:
    def countHomogenous(self, s: str) -> int:
        P = 10**9 + 7
        res = 0
        for _, seg in itertools.groupby(s):
            n = len(list(seg))
            res = (res + (1 + n) * n // 2) % P
        return res
