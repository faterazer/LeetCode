from typing import List


class Solution:
    def checkXMatrix(self, grid: List[List[int]]) -> bool:
        n = len(grid)
        for i, row in enumerate(grid):
            for j, x in enumerate(row):
                if i == j or i + j == n - 1:
                    if not x:
                        return False
                elif x:
                    return False
        return True
