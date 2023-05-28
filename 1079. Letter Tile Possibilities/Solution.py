from collections import Counter
from math import comb


class Solution:
    def numTilePossibilities(self, tiles: str) -> int:
        cnt = Counter(tiles)
        f = [1] + [0] * len(tiles)
        n = 0
        for c in cnt.values():
            n += c
            for i in range(n, 0, -1):
                for j in range(1, min(i, c) + 1):
                    f[i] += f[i - j] * comb(i, j)
        return sum(f[1:])
