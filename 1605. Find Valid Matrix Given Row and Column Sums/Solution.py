from typing import List


class Solution:
    def restoreMatrix(self, rowSum: List[int], colSum: List[int]) -> List[List[int]]:
        m, n = len(rowSum), len(colSum)
        i = j = 0
        res = [[0] * n for _ in range(m)]
        while i < m and j < n:
            res[i][j] = min(rowSum[i], colSum[j])
            rowSum[i] -= res[i][j]
            colSum[j] -= res[i][j]
            if rowSum[i] == 0:
                i += 1
            if colSum[j] == 0:
                j += 1
        return res
