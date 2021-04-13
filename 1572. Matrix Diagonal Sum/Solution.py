from typing import List


class Solution:
    def diagonalSum(self, mat: List[List[int]]) -> int:
        n = len(mat)
        res = sum(mat[i][i] + mat[i][n - 1 - i] for i in range(n))
        return res - mat[n // 2][n // 2] if n % 2 else res
