from typing import List


class Solution:
    def findPoisonedDuration(self, timeSeries: List[int], duration: int) -> int:
        res = 0
        for a, b in zip(timeSeries[:-1], timeSeries[1:]):
            res += min(duration, b - a)
        return res + duration
