class Solution:
    def numRollsToTarget(self, n: int, k: int, target: int) -> int:
        if target < n or target > n * k:
            return 0

        MOD = 10**9 + 7
        f = [1] + [0] * target
        for i in range(1, n + 1):
            for j in range(min(i * k, target), -1, -1):
                f[j] = 0
                for w in range(1, k + 1):
                    if j - w < 0:
                        break
                    f[j] = (f[j] + f[j - w]) % MOD
        return f[-1]
