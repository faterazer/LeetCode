from typing import List


class Solution:
    def minFallingPathSum(self, matrix: List[List[int]]) -> int:
        n = len(matrix)
        cur = matrix[0].copy()
        for i in range(1, n):
            pre = cur.copy()
            for j in range(n):
                cur[j] = pre[j]
                if j > 0:
                    cur[j] = min(cur[j], pre[j - 1])
                if j < n - 1:
                    cur[j] = min(cur[j], pre[j + 1])
                cur[j] += matrix[i][j]
        return min(cur)
