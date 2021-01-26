from typing import List


class Solution:
    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
        d = {}
        res = 0
        for domino in dominoes:
            key = min(domino) * 10 + max(domino)
            d[key] = d[key] + 1 if key in d else 1
            res += d[key] - 1
        return res
