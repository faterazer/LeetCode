from itertools import chain


class Solution:
    DIRECTIONS = ((0, 1), (1, 0), (0, -1), (-1, 0))

    def countUnguarded(self, m: int, n: int, guards: list[list[int]], walls: list[list[int]]) -> int:
        grid = [[0] * n for _ in range(m)]
        for x, y in chain(guards, walls):
            grid[x][y] = -1

        ans = m * n - len(guards) - len(walls)
        for x, y in guards:
            for dx, dy in self.DIRECTIONS:
                nx, ny = x + dx, y + dy
                while 0 <= nx < m and 0 <= ny < n and grid[nx][ny] != -1:
                    if grid[nx][ny] == 0:
                        grid[nx][ny] = 1
                        ans -= 1
                    nx += dx
                    ny += dy
        return ans
