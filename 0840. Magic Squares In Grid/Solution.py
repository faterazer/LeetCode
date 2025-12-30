class Solution:
    def numMagicSquaresInside(self, grid: list[list[int]]) -> int:
        m, n = len(grid), len(grid[0])
        result = 0
        for i in range(m - 2):
            for j in range(n - 2):
                if grid[i + 1][j + 1] != 5:
                    continue

                mask = 0
                row_sum, col_sum = [0, 0, 0], [0, 0, 0]
                for r in range(3):
                    for c in range(3):
                        x = grid[i + r][j + c]
                        mask |= 1 << x
                        row_sum[r] += x
                        col_sum[c] += x
                if mask == (1 << 10) - 2 and row_sum[0] == row_sum[1] == col_sum[0] == col_sum[1] == 15:
                    result += 1
        return result
