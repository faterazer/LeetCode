from typing import List


class Solution:
    def maxSumAfterPartitioning(self, arr: List[int], k: int) -> int:
        n = len(arr)
        dp = [0] * k
        for i in range(1, n + 1):
            max_val = best = 0
            for j in range(1, min(i, k) + 1):
                max_val = max(max_val, arr[i - j])
                best = max(best, dp[(i - j) % k] + max_val * j)
            dp[i % k] = best
        return dp[n % k]
