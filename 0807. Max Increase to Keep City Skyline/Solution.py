from itertools import product
from typing import List


class Solution:
    def maxIncreaseKeepingSkyline(self, grid: List[List[int]]) -> int:
        rows = map(max, grid)
        cols = map(max, zip(*grid))
        return sum(map(min, product(rows, cols))) - sum(map(sum, grid))
