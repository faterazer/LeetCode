class Solution:
    def minDeletionSize(self, strs: list[str]) -> int:
        m = len(strs[0])
        dp = [1] * m
        for j in range(1, m):
            for i in range(j):
                if dp[i] >= dp[j] and all(s[i] <= s[j] for s in strs):
                    dp[j] = dp[i] + 1
        return m - max(dp)
