from math import inf
from typing import List


class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:
        def getMinutes(s: str) -> int:
            return int(s[:2]) * 60 + int(s[3:])

        n = len(timePoints)
        if n > 1440:
            return 0
        timePoints.sort()
        return min(min(getMinutes(b) - getMinutes(a) for a, b in zip(timePoints, timePoints[1:])), getMinutes(timePoints[0]) + 1440 - getMinutes(timePoints[-1]))
