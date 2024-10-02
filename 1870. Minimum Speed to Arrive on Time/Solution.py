import bisect
from typing import List


class Solution:
    def minSpeedOnTime(self, dist: List[int], hour: float) -> int:
        n = len(dist)
        h100 = round(hour * 100)
        delta = h100 - (n - 1) * 100
        if delta <= 0:
            return -1

        max_dist = max(dist)
        if n - hour > 0:
            return max(max_dist, (dist[-1] * 100 - 1) // delta + 1)

        def check(v: int) -> bool:
            t = 0
            for d in dist[:-1]:
                t += (d - 1) // v + 1
            return (t * v + dist[-1]) * 100 <= h100 * v

        return bisect.bisect_left(range((max_dist - 1) // (h100 // (n * 100)) + 1), True, 1, check)
