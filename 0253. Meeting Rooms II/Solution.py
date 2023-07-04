import heapq
from typing import List


class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        pq = []
        res = 0
        for start, end in sorted(intervals):
            while pq and pq[0] <= start:
                heapq.heappop(pq)
            heapq.heappush(pq, end)
            res = max(res, len(pq))
        return res
