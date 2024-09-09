from typing import List


class Solution:
    def spiralMatrixIII(self, rows: int, cols: int, rStart: int, cStart: int) -> List[List[int]]:
        res = []
        x, y = rStart, cStart
        dx, dy, n = 0, 1, 0
        while len(res) < rows * cols:
            for _ in range(n // 2 + 1):
                if 0 <= x < rows and 0 <= y < cols:
                    res.append((x, y))
                x, y = x + dx, y + dy
            dx, dy, n = dy, -dx, n + 1
        return res
