class Solution:
    def findDiagonalOrder(self, mat: list[list[int]]) -> list[int]:
        m, n = len(mat), len(mat[0])
        ans = []
        for k in range(m + n):
            min_i, max_i = max(k - n + 1, 0), min(k, m - 1)
            if k % 2 == 0:
                for i in range(max_i, min_i - 1, -1):
                    ans.append(mat[i][k - i])
            else:
                for i in range(min_i, max_i + 1):
                    ans.append(mat[i][k - i])
        return ans
