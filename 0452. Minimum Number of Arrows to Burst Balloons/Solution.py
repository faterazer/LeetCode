from typing import List


class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points.sort(key=lambda x: x[1])

        pos = points[0][1]
        res = 1
        for start, end in points:
            if start > pos:
                pos = end
                res += 1
        return res
