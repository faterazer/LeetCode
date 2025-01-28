from typing import List


class Solution:
    def findMaxFish(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])

        def dfs(r: int, c: int) -> int:
            if r < 0 or r >= m or c < 0 or c >= n or grid[r][c] <= 0:
                return 0
            grid[r][c] *= -1
            return -grid[r][c] + dfs(r - 1, c) + dfs(r + 1, c) + dfs(r, c - 1) + dfs(r, c + 1)

        return max(dfs(r, c) for r in range(m) for c in range(n))
