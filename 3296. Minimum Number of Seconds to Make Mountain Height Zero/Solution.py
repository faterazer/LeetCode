from bisect import bisect_left
from heapq import heapify, heappop, heappush
from math import isqrt


class Solution:
    def minNumberOfSeconds_MK1(self, mountainHeight: int, workerTimes: list[int]) -> int:
        h = [(t, 2, t) for t in workerTimes]
        heapify(h)

        for _ in range(mountainHeight - 1):
            next_t, n, wt = heappop(h)
            heappush(h, (next_t + n * wt, n + 1, wt))
        return h[0][0]

    def minNumberOfSeconds_MK2(self, mountainHeight: int, workerTimes: list[int]) -> int:
        def check(m: int) -> bool:
            s = 0
            for t in workerTimes:
                s += (isqrt(8 * m // t + 1) - 1) // 2
                if s >= mountainHeight:
                    return True
            return False

        max_t = max(workerTimes)
        h = (mountainHeight - 1) // len(workerTimes) + 1
        return bisect_left(range(max_t * h * (1 + h) // 2), True, key=check)
