from typing import List


class Solution:
    def oddCells(self, n: int, m: int, indices: List[List[int]]) -> int:
        r, c = [False] * n, [False] * m
        for x, y in indices:
            r[x] ^= True
            c[y] ^= True
        return sum(x ^ y for x in r for y in c)
