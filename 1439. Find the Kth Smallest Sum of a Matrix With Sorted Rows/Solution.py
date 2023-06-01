from typing import List
import heapq


class Solution:
    def kthSmallest(self, mat: List[List[int]], k: int) -> int:
        def kSmallestPairs(A: List[int], B: List[int], k: int) -> List[int]:
            m, n = len(A), len(B)
            res = []
            heap = [(A[0] + B[0], 0, 0)]
            while heap and len(res) < k:
                total, i, j = heapq.heappop(heap)
                res.append(total)
                if j == 0 and i + 1 < m:
                    heapq.heappush(heap, (A[i + 1] + B[0], i + 1, 0))
                if j + 1 < n:
                    heapq.heappush(heap, (A[i] + B[j + 1], i, j + 1))
            return res

        buff = [0]
        for row in mat:
            buff = kSmallestPairs(buff, row, k)
        return buff[-1]
