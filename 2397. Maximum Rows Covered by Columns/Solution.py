from typing import List


class Solution:
    def maximumRows(self, matrix: List[List[int]], numSelect: int) -> int:
        m, n = len(matrix), len(matrix[0])
        masks = [sum(e << j for j, e in enumerate(row)) for row in matrix]

        res, x = 0, (1 << numSelect) - 1
        while x < (1 << n):
            res = max(res, sum((row & x) == row for row in masks))

            low_bit = x & -x
            x = (x + low_bit) | ((x ^ (x + low_bit)) // low_bit >> 2)
        return res
