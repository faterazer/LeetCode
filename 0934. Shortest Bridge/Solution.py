from collections import deque
from typing import List


class Solution:
    def shortestBridge(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        dirs = ((1, 0), (-1, 0), (0, 1), (0, -1))
        queue = deque([])

        def dfs(r: int, c: int) -> None:
            if r < 0 or r >= m or c < 0 or c >= n or grid[r][c] != 1:
                return
            grid[r][c] = -1
            queue.append((r, c))
            dfs(r + 1, c)
            dfs(r - 1, c)
            dfs(r, c + 1)
            dfs(r, c - 1)

        for i, row in enumerate(grid):
            for j, ele in enumerate(row):
                if ele:
                    dfs(i, j)
                    break
            if queue:
                break

        steps = 0
        while queue:
            size = len(queue)
            for _ in range(size):
                r, c = queue.popleft()
                for dr, dc in dirs:
                    nr, nc = r + dr, c + dc
                    if nr < 0 or nr >= m or nc < 0 or nc >= n or grid[nr][nc] == -1:
                        continue
                    if grid[nr][nc] == 1:
                        return steps
                    grid[nr][nc] = -1
                    queue.append((nr, nc))
            steps += 1
        return 0
