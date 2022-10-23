import bisect
from typing import List


class Solution:
    def jobScheduling(self, startTime: List[int], endTime: List[int], profit: List[int]) -> int:
        n = len(startTime)
        jobs = sorted(zip(startTime, endTime, profit), key=lambda x: x[1])
        dp = [0] * (n + 1)
        for i in range(1, n + 1):
            k = bisect.bisect(jobs, jobs[i - 1][0], key=lambda x: x[1])
            dp[i] = max(dp[i - 1], dp[k] + jobs[i - 1][2])
        return dp[-1]
