from typing import List


class Solution:
    def modifiedMatrix(self, matrix: List[List[int]]) -> List[List[int]]:
        for j in range(len(matrix[0])):
            mx = max(row[j] for row in matrix)
            for row in matrix:
                if row[j] == -1:
                    row[j] = mx
        return matrix
