from collections import Counter
from typing import List


class Solution:
    def maxEqualRowsAfterFlips(self, matrix: List[List[int]]) -> int:
        n = len(matrix[0])
        cnt = Counter()
        for row in matrix:
            if row[0]:
                for j in range(n):
                    row[j] ^= 1
            cnt[tuple(row)] += 1
        return max(cnt.values())
