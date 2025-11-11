class Solution:
    def findMaxForm(self, strs: list[str], m: int, n: int) -> int:
        dp = [[0] * (n + 1) for _ in range(m + 1)]
        sum0 = sum1 = 0
        for s in strs:
            count0 = s.count("0")
            count1 = len(s) - count0
            sum0 = min(sum0 + count0, m)
            sum1 = min(sum1 + count1, n)
            for i in range(sum0, count0 - 1, -1):
                for j in range(sum1, count1 - 1, -1):
                    dp[i][j] = max(dp[i][j], dp[i - count0][j - count1] + 1)
        return max(map(max, dp))
