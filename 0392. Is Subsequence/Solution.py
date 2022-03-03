class Solution:
    def isSubsequence_MK1(self, s: str, t: str) -> bool:
        t = iter(t)
        return all(c in t for c in s)

    def isSubsequence_MK2(self, s: str, t: str) -> bool:
        tn = len(t)
        dp = [[tn] * 26 for _ in range(tn + 1)]
        for i in range(tn - 1, -1, -1):
            for j in range(26):
                if ord('a') + j == ord(t[i]):
                    dp[i][j] = i
                else:
                    dp[i][j] = dp[i + 1][j]
        ti = 0
        for si, c in enumerate(s):
            if dp[ti][ord(s[si]) - ord('a')] == tn:
                return False
            ti = dp[ti][ord(c) - ord('a')] + 1
        return True
