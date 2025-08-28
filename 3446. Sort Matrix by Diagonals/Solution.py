class Solution:
    def sortMatrix(self, grid: list[list[int]]) -> list[list[int]]:
        n = len(grid)
        for k in range(2 * n - 1):
            r_start = n - 1 - k if k < n else 0
            c_start = 0 if k < n else k - n + 1

            buffer = []
            r, c = r_start, c_start
            while r < n and c < n:
                buffer.append(grid[r][c])
                r += 1
                c += 1

            if k < n:
                buffer.sort(reverse=True)
            else:
                buffer.sort()

            r, c = r_start, c_start
            for val in buffer:
                grid[r][c] = val
                r += 1
                c += 1
        return grid
