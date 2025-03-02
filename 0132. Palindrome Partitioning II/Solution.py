class Solution:
    def minCut(self, s: str) -> int:
        n = len(s)
        dp = [[True] * n for _ in range(n)]
        for j in range(1, n):
            for i in range(j):
                dp[i][j] = s[i] == s[j] and dp[i + 1][j - 1]

        f = [0] * n
        for j in range(1, n):
            if dp[0][j]:
                continue
            f[j] = min(f[i - 1] + 1 for i in range(j + 1) if dp[i][j])
        return f[-1]
