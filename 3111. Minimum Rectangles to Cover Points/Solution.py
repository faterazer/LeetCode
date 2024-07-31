from typing import List


class Solution:
    def minRectanglesToCoverPoints(self, points: List[List[int]], w: int) -> int:
        points.sort(key=lambda x: x[0])
        res, beg = 1, points[0][0]
        for x, _ in points:
            if x - beg > w:
                res += 1
                beg = x
        return res
