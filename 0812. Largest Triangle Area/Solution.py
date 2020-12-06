from typing import List
import itertools


class Solution:
    def largestTriangleArea(self, points: List[List[int]]) -> float:
        return max(0.5 * abs((a[0] - b[0]) * (c[1] - b[1]) - (a[1] - b[1]) * (c[0] - b[0])) for a, b, c in itertools.combinations(points, 3))
