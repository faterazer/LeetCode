from typing import List


class Solution:
    def findPeakGrid(self, mat: List[List[int]]) -> List[int]:
        l, r = 0, len(mat) - 2
        while l <= r:
            i = l + (r - l) // 2
            j = mat[i].index(max(mat[i]))
            if mat[i][j] < mat[i + 1][j]:
                l = i + 1
            else:
                r = i - 1
        return [l, mat[l].index(max(mat[l]))]
