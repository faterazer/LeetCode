import math


class Solution:
    def soupServings(self, n: int) -> float:
        n = math.ceil(n / 25)
        if n >= 179:
            return 1.0
        memo = [[-1.0] * 179 for _ in range(179)]

        def dfs(a: int, b: int) -> float:
            if a <= 0 and b <= 0:
                return 0.5
            if a <= 0:
                return 1.0
            if b <= 0:
                return 0.0
            if memo[a][b] < 0.0:
                memo[a][b] = 0.25 * (
                    dfs(a - 4, b) + dfs(a - 3, b - 1) + dfs(a - 2, b - 2) + dfs(a - 1, b - 3)
                )
            return memo[a][b]

        return dfs(n, n)
