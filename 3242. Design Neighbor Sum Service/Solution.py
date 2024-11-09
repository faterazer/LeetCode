from typing import List


DIRECTIONS = ((-1, 0), (1, 0), (0, -1), (0, 1), (1, 1), (-1, 1), (-1, -1), (1, -1))


class NeighborSum:

    def __init__(self, grid: List[List[int]]):
        n = len(grid)
        self.data = [[0, 0] for _ in range(n * n)]
        for i, row in enumerate(grid):
            for j, v in enumerate(row):
                for k, (di, dj) in enumerate(DIRECTIONS):
                    ni, nj = i + di, j + dj
                    if 0 <= ni < n and 0 <= nj < n:
                        self.data[v][k // 4] += grid[ni][nj]
        self.data = tuple(self.data)

    def adjacentSum(self, value: int) -> int:
        return self.data[value][0]

    def diagonalSum(self, value: int) -> int:
        return self.data[value][1]


# Your NeighborSum object will be instantiated and called as such:
# obj = NeighborSum(grid)
# param_1 = obj.adjacentSum(value)
# param_2 = obj.diagonalSum(value)
