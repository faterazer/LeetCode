from typing import List


class Solution:
    def minFlips(self, grid: List[List[int]]) -> int:
        row_ans = col_ans = 0
        for row in grid:
            for j in range(len(row) // 2):
                row_ans += row[j] != row[-1 - j]

        for col in zip(*grid):
            for i in range(len(col) // 2):
                col_ans += col[i] != col[-1 - i]

        return min(row_ans, col_ans)
