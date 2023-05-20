from itertools import accumulate
from typing import List


class Solution:
    def minDifficulty(self, jobDifficulty: List[int], d: int) -> int:
        n = len(jobDifficulty)
        if n < d:
            return -1

        dp = list(accumulate(jobDifficulty, max))
        for i in range(1, d):
            stack = []
            next_dp = [0] * n
            for j in range(i, n):
                pre_min = dp[j - 1]
                while stack and jobDifficulty[stack[-1][0]] < jobDifficulty[j]:
                    pre_min = min(pre_min, stack.pop()[1])
                if stack:
                    next_dp[j] = min(pre_min + jobDifficulty[j], next_dp[stack[-1][0]])
                else:
                    next_dp[j] = pre_min + jobDifficulty[j]
                stack.append((j, pre_min))
            dp = next_dp
        return dp[-1]
