import heapq
from typing import List


class Solution:
    def maxKelements(self, nums: List[int], k: int) -> int:
        max_heap = [-e for e in nums]
        heapq.heapify(max_heap)
        res = 0
        for _ in range(k):
            res -= heapq.heapreplace(max_heap, max_heap[0] // 3)
        return res
