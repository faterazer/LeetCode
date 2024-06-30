from typing import List


class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        s = sum(nums) - abs(target)
        if s < 0 or s % 2:
            return 0
        m = s // 2

        f = [1] + [0] * m
        for x in nums:
            for i in range(m, x - 1, -1):
                f[i] += f[i - x]
        return f[m]
