from math import inf


class Solution:
    def maximumAmount(self, coins: list[list[int]]) -> int | float:
        n = len(coins[0])
        f = [[-inf] * 3 for _ in range(n + 1)]
        f[1] = [0] * 3
        for row in coins:
            for j, x in enumerate(row):
                f[j + 1][2] = max(f[j][2] + x, f[j + 1][2] + x, f[j][1], f[j + 1][1])
                f[j + 1][1] = max(f[j][1] + x, f[j + 1][1] + x, f[j][0], f[j + 1][0])
                f[j + 1][0] = max(f[j][0], f[j + 1][0]) + x
        return f[n][2]
