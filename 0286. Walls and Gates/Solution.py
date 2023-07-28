from collections import deque
from typing import List


class Solution:
    def wallsAndGates(self, rooms: List[List[int]]) -> None:
        """
        Do not return anything, modify rooms in-place instead.
        """
        m, n = len(rooms), len(rooms[0])
        queue = deque([])
        for i, row in enumerate(rooms):
            for j, room in enumerate(row):
                if room == 0:
                    queue.append((i, j))

        directions = ((0, 1), (0, -1), (1, 0), (-1, 0))
        while queue:
            r, c = queue.popleft()
            for dr, dc in directions:
                nr, nc = r + dr, c + dc
                if nr < 0 or nr >= m or nc < 0 or nc >= n or rooms[nr][nc] != 2147483647:
                    continue
                rooms[nr][nc] = rooms[r][c] + 1
                queue.append((nr, nc))
