from typing import List


class Solution:
    def onesMinusZeros(self, grid: List[List[int]]) -> List[List[int]]:
        r, c = [0] * len(grid), [0] * len(grid[0])
        for i, row in enumerate(grid):
            for j, x in enumerate(row):
                r[i] += 2 * x - 1
                c[j] += 2 * x - 1
        return [[x + y for y in c] for x in r]
