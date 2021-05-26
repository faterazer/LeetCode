import math
from typing import List


class Solution:
    def nearestValidPoint(self, x: int, y: int, points: List[List[int]]) -> int:
        res, dist = -1, math.inf
        for i, (xx, yy) in enumerate(points):
            if xx == x or yy == y:
                tmp = abs(xx - x) + abs(yy - y)
                if tmp < dist:
                    dist = tmp
                    res = i
        return res
