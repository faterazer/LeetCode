class Solution:
    def numTilings(self, n: int) -> int:
        P = 10**9 + 7
        dp = [1, 2, 5]
        if n <= 3:
            return dp[n - 1]
        for _ in range(4, n + 1):
            dp = [dp[1], dp[2], (2 * dp[2] % P + dp[0]) % P]
        return dp[-1]
