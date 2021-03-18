from typing import List


class Solution:
    def busyStudent(self, startTime: List[int], endTime: List[int], queryTime: int) -> int:
        return sum(l <= queryTime <= r for l, r in zip(startTime, endTime))
        