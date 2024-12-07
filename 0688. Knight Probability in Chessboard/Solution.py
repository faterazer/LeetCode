directions = ((1, -2), (2, -1), (2, 1), (1, 2), (-1, 2), (-2, 1), (-2, -1), (-1, -2))


class Solution:
    def knightProbability(self, n: int, k: int, row: int, column: int) -> float:
        f = [[1.0] * n for _ in range(n)]
        for _ in range(k):
            next_f = [[0.0] * n for _ in range(n)]
            for i in range(n):
                for j in range(n):
                    for di, dj in directions:
                        ni, nj = i + di, j + dj
                        if 0 <= ni < n and 0 <= nj < n:
                            next_f[i][j] += 1.0 / 8.0 * f[ni][nj]
            f = next_f
        return f[row][column]
