from math import inf
from typing import List

class Solution:
    def minPathCost(self, grid: List[List[int]], moveCost: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        res = grid[0].copy()
        for i in range(m - 1):
            buff = [inf] * n
            for j in range(n):
                for k in range(n):
                    buff[k] = min(buff[k], res[j] + moveCost[grid[i][j]][k] + grid[i + 1][k])
            res = buff
        return min(res)
