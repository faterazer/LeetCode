class Solution:
    def countSquares(self, matrix: list[list[int]]) -> int:
        for i, row in enumerate(matrix):
            for j, x in enumerate(row):
                if i and j and matrix[i][j]:
                    matrix[i][j] += min(matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1])
        return sum(map(sum, matrix))
