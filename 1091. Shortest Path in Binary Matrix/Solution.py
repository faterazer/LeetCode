from collections import deque
from typing import List


class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        if grid[0][0] or grid[m - 1][n - 1]:
            return -1
        if m == 1 and n == 1:
            return 1

        directions = ((-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1))
        visited = [[False] * n for _ in range(m)]
        visited[0][0] = True
        frontier = deque([(0, 0)])
        steps = 0
        while frontier:
            steps += 1
            size = len(frontier)
            for _ in range(size):
                r, c = frontier.popleft()
                for dr, dc in directions:
                    nr, nc = r + dr, c + dc
                    if nr < 0 or nr >= m or nc < 0 or nc >= n or grid[nr][nc] or visited[nr][nc]:
                        continue
                    if nr == m - 1 and nc == n - 1:
                        return steps + 1
                    visited[nr][nc] = True
                    frontier.append((nr, nc))
        return -1
