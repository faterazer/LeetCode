from collections import deque
from typing import List


class Solution:
    def shortestPathAllKeys(self, grid: List[str]) -> int:
        dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]

        m, n = len(grid), len(grid[0])
        x = y = all_keys = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == "@":
                    x, y = i, j
                elif grid[i][j].islower():
                    all_keys |= 1 << (ord(grid[i][j]) - ord("a"))

        queue = deque([(x, y, 0)])
        visited = [[set() for _ in range(n)] for _ in range(m)]
        visited[x][y].add(0)
        steps = 0
        while queue:
            size = len(queue)
            for _ in range(size):
                x, y, k = queue.popleft()
                for dx, dy in dirs:
                    nx, ny, keys = x + dx, y + dy, k
                    if nx < 0 or nx >= m or ny < 0 or ny >= n or grid[nx][ny] == "#":
                        continue
                    if grid[nx][ny].isupper() and not (keys & (1 << (ord(grid[nx][ny]) - ord("A")))):
                        continue
                    if grid[nx][ny].islower():
                        keys |= 1 << (ord(grid[nx][ny]) - ord("a"))
                    if keys in visited[nx][ny]:
                        continue
                    if keys == all_keys:
                        return steps + 1
                    queue.append((nx, ny, keys))
                    visited[nx][ny].add(keys)
            steps += 1
        return -1
