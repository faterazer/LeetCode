from typing import List


class Solution:
    def numberOfRightTriangles(self, grid: List[List[int]]) -> int:
        col_sum = [sum(col, -1) for col in zip(*grid)]
        res = 0
        for row in grid:
            row_sum = sum(row, -1)
            res += row_sum * sum(cs for x, cs in zip(row, col_sum) if x)
        return res
