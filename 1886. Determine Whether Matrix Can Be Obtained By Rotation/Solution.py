from typing import List


class Solution:
    def findRotation(self, mat: List[List[int]], target: List[List[int]]) -> bool:
        res = [True] * 4
        n = len(mat)
        for i in range(n):
            for j in range(n):
                if mat[i][j] != target[i][j]:
                    res[0] = False
                if mat[i][j] != target[j][n - 1 - i]:
                    res[1] = False
                if mat[i][j] != target[n - 1 - i][n - 1 - j]:
                    res[2] = False
                if mat[i][j] != target[n - 1 - j][i]:
                    res[3] = False
        return any(res)
