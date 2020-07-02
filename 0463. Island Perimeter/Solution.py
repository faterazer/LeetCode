from typing import List


class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        islands, neighbours = 0, 0
        for i in range(m):
            for j in range(n):
                if grid[i][j]:
                    islands += 1
                    if i < m - 1 and grid[i+1][j]:
                        neighbours += 1
                    if j < n - 1 and grid[i][j+1]:
                        neighbours += 1
        return islands * 4 - neighbours * 2
