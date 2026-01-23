class Solution:
    def maxSideLength(self, mat: list[list[int]], threshold: int) -> int:
        m, n = len(mat), len(mat[0])
        pre_sum = [[0] * (n + 1) for _ in range(m + 1)]
        for i, row in enumerate(mat):
            for j, x in enumerate(row):
                pre_sum[i + 1][j + 1] = pre_sum[i + 1][j] + pre_sum[i][j + 1] - pre_sum[i][j] + x

        def query(r1: int, c1: int, r2: int, c2: int) -> int:
            return pre_sum[r2 + 1][c2 + 1] - pre_sum[r2 + 1][c1] - pre_sum[r1][c2 + 1] + pre_sum[r1][c1]

        result = 0
        for i in range(m):
            for j in range(n):
                while i + result < m and j + result < n and query(i, j, i + result, j + result) <= threshold:
                    result += 1
        return result
