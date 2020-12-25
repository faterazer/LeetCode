from typing import List


class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        area, N = 0, len(grid)
        for i in range(N):
            for j in range(N):
                if grid[i][j]:
                    area += (grid[i][j] << 2) + 2
                    area -= min(grid[i-1][j], grid[i][j]) << 1 if i > 0 else 0
                    area -= min(grid[i][j-1], grid[i][j]) << 1 if j > 0 else 0
        return area
