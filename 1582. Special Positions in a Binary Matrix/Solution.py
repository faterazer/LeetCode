from typing import List


class Solution:
    def numSpecial(self, mat: List[List[int]]) -> int:
        m, n = len(mat), len(mat[0])
        rows_sum = [sum(row) for row in mat]
        cols_sum = [sum(row) for row in zip(*mat)]
        return sum(mat[i][j] and rows_sum[i] == 1 and cols_sum[j] == 1 for i in range(m) for j in range(n))
