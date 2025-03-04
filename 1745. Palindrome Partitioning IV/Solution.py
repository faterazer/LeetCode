class Solution:
    def checkPartitioning(self, s: str) -> bool:

        def palindromePartition(s: str, k: int) -> int:
            n = len(s)
            cost = [[0] * n for _ in range(n)]
            for j in range(n):
                for i in range(j + 1):
                    cost[i][j] = s[i] != s[j]
                    cost[i][j] += cost[i + 1][j - 1] if j - i > 1 else 0

            f = cost[0]
            for i in range(1, k):
                for r in range(n - 1, i - 1, -1):
                    f[r] = min((f[l - 1] + cost[l][r] for l in range(i, r + 1)), default=0)
            return f[-1]

        return palindromePartition(s, 3) == 0
