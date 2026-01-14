from collections import defaultdict
from itertools import pairwise


class Solution:
    def separateSquares(self, squares: list[list[int]]) -> float:
        total_area = 0
        diff = defaultdict(int)
        for _, y, side in squares:
            total_area += side * side
            diff[y] += side
            diff[y + side] -= side

        area = accum_side = 0
        for y1, y2 in pairwise(sorted(diff)):
            accum_side += diff[y1]
            area += accum_side * (y2 - y1)
            if area * 2 >= total_area:
                return y2 - (area * 2 - total_area) / (2 * accum_side)
        return -1
