from typing import List


class Solution:
    def searchMatrix_MK1(self, matrix: List[List[int]], target: int) -> bool:
        m, n = len(matrix), len(matrix[0])
        i, j = 0, n - 1
        while i < m and j >= 0:
            if matrix[i][0] > target:
                return False
            if matrix[i][j] < target:
                i +=1
            elif matrix[i][j] > target:
                j -= 1
            else:
                return True
        return False

    def searchMatrix_MK2(self, matrix: List[List[int]], target: int) -> bool:
        m, n = len(matrix), len(matrix[0])
        l, r = 0, m * n - 1
        while l <= r:
            mid = l + ((r - l) >> 1)
            val = matrix[mid // n][mid % n]
            if val < target:
                l = mid + 1
            elif val > target:
                r = mid - 1
            else:
                return True
        return False
