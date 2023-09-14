import heapq
from typing import List


class Solution:
    def scheduleCourse(self, courses: List[List[int]]) -> int:
        courses.sort(key=lambda x: x[1])
        max_heap = []
        cur_day = 0
        for duration, lastday in courses:
            if cur_day + duration <= lastday:
                cur_day += duration
                heapq.heappush(max_heap, -duration)
            elif max_heap and duration < -max_heap[0]:
                cur_day -= -heapq.heappop(max_heap) - duration
                heapq.heappush(max_heap, -duration)
        return len(max_heap)
