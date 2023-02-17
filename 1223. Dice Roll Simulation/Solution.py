from typing import List


class Solution:
    def dieSimulator(self, n: int, rollMax: List[int]) -> int:
        MOD = 10**9 + 7
        m = len(rollMax)
        dp, s = [[0] * m for _ in range(n)], [0] * n
        for i in range(m):
            dp[0][i] = 1
        s[0] = m

        for i in range(1, n):
            for j in range(m):
                dp[i][j] = s[i - 1]
                if i == rollMax[j]:
                    dp[i][j] -= 1
                elif i > rollMax[j]:
                    dp[i][j] -= s[i - rollMax[j] - 1] - dp[i - rollMax[j] - 1][j]
                dp[i][j] %= MOD
            s[i] = sum(dp[i]) % MOD
        return s[n - 1]
