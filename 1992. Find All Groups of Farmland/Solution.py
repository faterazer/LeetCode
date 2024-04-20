from typing import List


class Solution:
    def findFarmland(self, land: List[List[int]]) -> List[List[int]]:
        m, n = len(land), len(land[0])
        res = []

        for i in range(m):
            for j in range(n):
                if land[i][j] != 1:
                    continue

                r, c = i, j
                while r + 1 < m and land[r + 1][j] == 1:
                    r += 1
                while c + 1 < n and land[i][c + 1] == 1:
                    c += 1
                res.append([i, j, r, c])

                for x in range(i, r + 1):
                    for y in range(j, c + 1):
                        land[x][y] = 2
        return res
