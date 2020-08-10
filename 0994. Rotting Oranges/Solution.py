from collections import deque
from typing import List


class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        queue = deque()
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 2:
                    queue.append((i, j, 0))
        
        def neighbors(i, j):
            for ni, nj in ((i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1)):
                if 0 <= ni < m and 0 <= nj < n:
                    yield ni, nj
        
        d = 0
        while queue:
            i, j, d = queue.popleft()
            for ni, nj in neighbors(i, j):
                if grid[ni][nj] == 1:
                    grid[ni][nj] = 2
                    queue.append((ni, nj, d + 1))
        
        if any(1 in row for row in grid):
            return -1
        return d
