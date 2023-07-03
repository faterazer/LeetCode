from typing import List


class Solution:
    def canAttendMeetings(self, intervals: List[List[int]]) -> bool:
        intervals.sort(key=lambda x: x[0])
        for a, b in zip(intervals, intervals[1:]):
            if b[0] < a[1]:
                return False
        return True
