from math import inf


class Solution:
    def maximumProfit(self, prices: list[int], k: int) -> int:
        dp = [[0, -inf, -inf] for _ in range(k + 2)]
        for p in prices:
            for i in range(k + 1, 0, -1):
                dp[i][1] = max(dp[i][1], dp[i][0] - p)
                dp[i][2] = max(dp[i][2], dp[i][0] + p)
                dp[i][0] = max(dp[i][0], dp[i - 1][1] + p, dp[i - 1][2] - p)
        return dp[k + 1][0]
