from typing import List


class Solution:
    def numMovesStones(self, a: int, b: int, c: int) -> List[int]:
        a, b, c = sorted([a, b, c])
        if c - a == 2:
            return [0, 0]
        return [1 if min(b - a, c - b) <= 2 else 2, c - a - 2]
