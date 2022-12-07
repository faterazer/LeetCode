from itertools import accumulate
from typing import List


class Solution:
    def largestSumOfAverages(self, nums: List[int], k: int) -> float:
        n = len(nums)
        pre_sum = [0] + list(accumulate(nums))
        dp = [0] + [pre_sum[i] / i for i in range(1, n + 1)]
        for i in range(2, k + 1):
            for j in range(n, i - 1, -1):
                for w in range(j):
                    dp[j] = max(dp[j], dp[w] + (pre_sum[j] - pre_sum[w]) / (j - w))
        return dp[-1]
