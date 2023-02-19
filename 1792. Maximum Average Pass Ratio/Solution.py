import heapq
from typing import List


class Solution:
    def maxAverageRatio(self, classes: List[List[int]], extraStudents: int) -> float:
        def profit(a: float, b: float) -> float:
            return (a + 1) / (b + 1) - a / b

        heap = [(-profit(a, b), a, b) for a, b in classes]
        heapq.heapify(heap)

        for _ in range(extraStudents):
            _, a, b = heapq.heappop(heap)
            heapq.heappush(heap, (-profit(a + 1, b + 1), a + 1, b + 1))

        return sum(a / b for _, a, b in heap) / len(classes)
