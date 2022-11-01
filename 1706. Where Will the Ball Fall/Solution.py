from typing import List


class Solution:
    def findBall(self, grid: List[List[int]]) -> List[int]:
        n = len(grid[0])
        res = [0] * n
        for i in range(n):
            j = i
            for row in grid:
                k, j = j, j + row[j]
                if j < 0 or j >= n or row[k] != row[j]:
                    j = -1
                    break
            res[i] = j
        return res
