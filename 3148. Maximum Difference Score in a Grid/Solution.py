import math
from typing import List


class Solution:
    def maxScore(self, grid: List[List[int]]) -> int:
        n, res = len(grid[0]), -math.inf
        col_min = [math.inf] * n
        for row in grid:
            min_val = math.inf
            for i, e in enumerate(row):
                res = max(res, e - min(min_val, col_min[i]))
                min_val = min(min_val, e)
                col_min[i] = min(col_min[i], min_val)
        return res
