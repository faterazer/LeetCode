from math import floor
from typing import List


class Solution:
    def bestCoordinate(self, towers: List[List[int]], radius: int) -> List[int]:
        towers_T = list(zip(*towers))
        x_min, x_max = min(towers_T[0]), max(towers_T[0])
        y_min, y_max = min(towers_T[1]), max(towers_T[1])

        res, max_quality = [0] * 2, 0
        for x in range(x_min, x_max + 1):
            for y in range(y_min, y_max + 1):
                quality = 0
                for xt, yt, qt in towers:
                    d2 = (x - xt) ** 2 + (y - yt) ** 2
                    if d2 <= radius**2:
                        quality += floor(qt / (1 + d2**0.5))
                if quality > max_quality:
                    max_quality = quality
                    res = [x, y]
        return res
