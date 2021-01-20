from typing import List


class Solution:
    def addToArrayForm(self, A: List[int], K: int) -> List[int]:
        for i in range(len(A) - 1, -1, -1):
            K, A[i] = divmod(A[i] + K, 10)
        return [int(x) for x in str(K)] + A if K else A
        