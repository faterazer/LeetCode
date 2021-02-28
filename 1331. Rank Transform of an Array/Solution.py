from typing import List


class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        rank = {}
        for x in sorted(arr):
            rank.setdefault(x, len(rank) + 1)
        return [rank.get(x) for x in arr]
