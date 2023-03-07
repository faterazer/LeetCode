import bisect
from typing import List


class Solution:
    def minimumTime(self, time: List[int], totalTrips: int) -> int:
        return bisect.bisect_left(range(totalTrips * min(time)), totalTrips, key=lambda x: sum(x // t for t in time))
