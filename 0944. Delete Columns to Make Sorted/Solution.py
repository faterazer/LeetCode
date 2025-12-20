from itertools import pairwise


class Solution:
    def minDeletionSize(self, A: list[str]) -> int:
        result, m, n = 0, len(A), len(A[0])
        for col in zip(*A):
            if any(x > y for x, y in pairwise(col)):
                result += 1
        return result
