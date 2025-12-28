class Solution:
    def countNegatives(self, grid: list[list[int]]) -> int:
        m, n = len(grid), len(grid[0])
        i, j, res = 0, n - 1, 0
        while i < m and j >= 0:
            while j >= 0 and grid[i][j] < 0:
                j -= 1
            res += n - j - 1
            i += 1
        return res + (m - i) * n
