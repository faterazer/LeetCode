from typing import List


class Solution:
    def garbageCollection(self, garbage: List[str], travel: List[int]) -> int:
        seen = set()
        res = len(garbage[0])
        for g, t in zip(reversed(garbage), reversed(travel)):
            seen.update(g)
            res += t * len(seen) + len(g)
        return res
