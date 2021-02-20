from typing import List


class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        m, n = len(grid), len(grid[0])
        size = m * n
        k %= size
        if not k:
            return grid

        def gridReverse(grid: List[List[int]], beg: int, end : int) -> None:
            n = len(grid[0])
            while beg < end:
                x1, y1 = divmod(beg, n)
                x2, y2 = divmod(end, n)
                grid[x1][y1], grid[x2][y2] = grid[x2][y2], grid[x1][y1]
                beg += 1
                end -= 1

        gridReverse(grid, 0, size - k - 1)
        gridReverse(grid, size - k, size - 1)
        gridReverse(grid, 0, size - 1);
        return grid
