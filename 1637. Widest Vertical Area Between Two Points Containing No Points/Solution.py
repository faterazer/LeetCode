from typing import List


class Solution:
    def maxWidthOfVerticalArea(self, points: List[List[int]]) -> int:
        points.sort()
        return max(a[0] - b[0] for a, b in zip(points[1:], points))
