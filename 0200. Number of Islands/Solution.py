from typing import List


class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        m, n = len(grid), len(grid[0])

        def expand(grid: List[List[str]], r: int, c: int) -> None:
            if r < 0 or r >= m or c < 0 or c >= n or grid[r][c] != '1':
                return
            grid[r][c] = '2'
            expand(grid, r + 1, c)
            expand(grid, r - 1, c)
            expand(grid, r, c + 1)
            expand(grid, r, c - 1)

        res = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == '1':
                    res += 1
                    expand(grid, i, j)
        return res
