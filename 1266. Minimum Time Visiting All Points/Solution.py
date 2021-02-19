from typing import List


class Solution:
    def minTimeToVisitAllPoints(self, points: List[List[int]]) -> int:
        return sum(max(abs(a[0] - b[0]), abs(a[1] - b[1])) for a, b in zip(points[1:], points))
