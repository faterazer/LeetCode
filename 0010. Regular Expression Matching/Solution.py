class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        sn, pn = len(s), len(p)
        dp = [[False] * (pn + 1) for _ in range(sn + 1)]
        dp[0][0] = True
        for i in range(0, sn + 1):
            for j in range(1, pn + 1):
                if i > 0 and (s[i - 1] == p[j - 1] or p[j - 1] == '.'):
                    dp[i][j] = dp[i - 1][j - 1]
                elif p[j - 1] == '*':
                    dp[i][j] = dp[i][j - 2]
                    if i > 0 and (s[i - 1] == p[j - 2] or p[j - 2] == '.'):
                        dp[i][j] |= dp[i - 1][j]
        return dp[sn][pn]
