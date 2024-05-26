import heapq
from typing import List


class Solution:
    def kthLargestValue(self, matrix: List[List[int]], k: int) -> int:
        m, n = len(matrix), len(matrix[0])
        min_heap = []
        for i in range(m):
            for j in range(n):
                matrix[i][j] ^= matrix[i - 1][j] if i > 0 else 0
                matrix[i][j] ^= matrix[i][j - 1] if j > 0 else 0
                matrix[i][j] ^= matrix[i - 1][j - 1] if i > 0 and j > 0 else 0
                heapq.heappush(min_heap, matrix[i][j])
                if len(min_heap) > k:
                    heapq.heappop(min_heap)
        return min_heap[0]
