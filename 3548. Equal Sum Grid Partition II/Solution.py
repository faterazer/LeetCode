from collections.abc import Sequence


class Solution:
    def canPartitionGrid(self, grid: list[list[int]]) -> bool:
        total = sum(sum(row) for row in grid)

        def check(matrix: Sequence[Sequence[int]]) -> bool:
            m, n = len(matrix), len(matrix[0])
            if m <= 1:
                return False

            top_sum = sum(matrix[0])
            if 2 * top_sum - total in {0, matrix[0][0], matrix[0][-1]}:
                return True

            if m == 2:
                return False

            seen = set(matrix[0])
            seen.add(0)

            for i in range(1, m - 1):
                top_sum += sum(matrix[i])
                seen.update(matrix[i])

                diff = 2 * top_sum - total
                if n == 1:
                    if diff in {0, matrix[0][0], matrix[i][0]}:
                        return True
                else:
                    if diff in seen:
                        return True
            return False

        transposed = list(zip(*grid))
        return check(grid) or check(grid[::-1]) or check(transposed) or check(transposed[::-1])
