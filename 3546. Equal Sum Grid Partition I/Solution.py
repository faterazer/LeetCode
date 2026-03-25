from collections.abc import Iterable


class Solution:
    def canPartitionGrid(self, grid: list[list[int]]) -> bool:
        total_sum = sum(sum(row) for row in grid)

        def check(matrix: Iterable[Iterable[int]]) -> bool:
            s = 0
            for row in matrix:
                s += sum(row)
                if s * 2 == total_sum:
                    return True
            return False

        return check(grid) or check(zip(*grid))
