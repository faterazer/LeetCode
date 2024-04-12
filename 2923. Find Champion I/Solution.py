from typing import List


class Solution:
    def findChampion(self, grid: List[List[int]]) -> int:
        res = 0
        for i, row in enumerate(grid):
            if row[res] == 1:
                res = i
        return res
