from typing import List


class Solution:
    def minDeletionSize(self, A: List[str]) -> int:
        res, m, n = 0, len(A), len(A[0])
        for i in range(0, n):
            for j in range(1, m):
                if A[j][i] < A[j - 1][i]:
                    res += 1
                    break
        return res
