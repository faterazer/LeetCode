from typing import List


class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        m, n = len(obstacleGrid), len(obstacleGrid[0])
        obstacleGrid[0][0] ^= 1
        for i in range(1, m):
            obstacleGrid[i][0] = 0 if obstacleGrid[i][0] else obstacleGrid[i - 1][0]
        for j in range(1, n):
            obstacleGrid[0][j] = 0 if obstacleGrid[0][j] else obstacleGrid[0][j - 1]
        for i in range(1, m):
            for j in range(1, n):
                if obstacleGrid[i][j]:
                    obstacleGrid[i][j] = 0
                else:
                    obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1]
        return obstacleGrid[m - 1][n - 1]
