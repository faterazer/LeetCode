import heapq
from typing import List


class Solution:
    def largestSumAfterKNegations(self, A: List[int], K: int) -> int:
        heapq.heapify(A)
        for _ in range(K):
            heapq.heapreplace(A, -A[0])
        return sum(A)
