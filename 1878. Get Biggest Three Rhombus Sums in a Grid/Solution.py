class Solution:
    def getBiggestThree(self, grid: list[list[int]]) -> list[int]:
        m, n = len(grid), len(grid[0])
        diag_sum = [[0] * (n + 1) for _ in range(m + 1)]
        anti_sum = [[0] * (n + 1) for _ in range(m + 1)]
        for i, row in enumerate(grid):
            for j, v in enumerate(row):
                diag_sum[i + 1][j + 1] = diag_sum[i][j] + v
                anti_sum[i + 1][j] = anti_sum[i][j + 1] + v

        def query_diagonal(x: int, y: int, k: int) -> int:
            # 从 (x, y) 开始，对角线方向连续 k 个元素和
            return diag_sum[x + k][y + k] - diag_sum[x][y]

        def query_anti_diagonal(x: int, y: int, k: int) -> int:
            # 从 (x, y) 开始，反对角线方向连续 k 个元素和
            return anti_sum[x + k][y + 1 - k] - anti_sum[x][y + 1]

        result = [0, 0, 0]

        def update(x: int) -> None:
            nonlocal result
            if x > result[0]:
                result = [x, result[0], result[1]]
            elif result[1] < x < result[0]:
                result = [result[0], x, result[1]]
            elif result[2] < x < result[1]:
                result[2] = x

        # 枚举菱形正中心 (i,j)
        for i, row in enumerate(grid):
            for j, v in enumerate(row):
                update(v)
                mx = min(i, m - 1 - i, j, n - 1 - j)
                for k in range(1, mx + 1):
                    a = query_diagonal(i, j - k, k)
                    b = query_diagonal(i - k, j, k)
                    c = query_anti_diagonal(i - k + 1, j - 1, k - 1)
                    d = query_anti_diagonal(i, j + k, k + 1)
                    update(a + b + c + d)

        while result[-1] == 0:
            result.pop()
        return result
