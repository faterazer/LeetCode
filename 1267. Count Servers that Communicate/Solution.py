from typing import List


class Solution:
    def countServers(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        row_sum, col_sum = [0] * m, [0] * n
        for i in range(m):
            for j in range(n):
                row_sum[i] += grid[i][j]
                col_sum[j] += grid[i][j]
        return sum(grid[i][j] and (row_sum[i] > 1 or col_sum[j] > 1) for i in range(m) for j in range(n))
