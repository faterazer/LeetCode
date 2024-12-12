import heapq
from typing import List


class Solution:
    def maxSpending(self, values: List[List[int]]) -> int:
        m, n = len(values), len(values[0])
        pq = [(values[i][-1], i, n - 1) for i in range(m)]
        heapq.heapify(pq)
        ans = 0
        for d in range(1, m * n + 1):
            v, r, c = heapq.heappop(pq)
            ans += d * v
            if c > 0:
                heapq.heappush(pq, (values[r][c - 1], r, c - 1))
        return ans
