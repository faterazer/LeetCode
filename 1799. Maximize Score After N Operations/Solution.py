from math import gcd
from typing import List


class Solution:
    def maxScore(self, nums: List[int]) -> int:
        n = len(nums)

        gcd_tmp = {}
        for i in range(n):
            for j in range(i + 1, n):
                gcd_tmp[(i, j)] = gcd(nums[i], nums[j])

        dp = [0] * (1 << n)
        for i in range(len(dp)):
            bit_cnt = i.bit_count()
            if bit_cnt & 1:
                continue

            for j in range(n):
                if (i >> j) & 1:
                    for k in range(j + 1, n):
                        if (i >> k) & 1:
                            dp[i] = max(
                                dp[i], dp[i ^ (1 << j) ^ (1 << k)] + bit_cnt // 2 * gcd_tmp[(j, k)]
                            )
        return dp[-1]
