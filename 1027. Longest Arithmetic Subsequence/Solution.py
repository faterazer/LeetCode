from typing import List


class Solution:
    def longestArithSeqLength(self, nums: List[int]) -> int:
        min_val, max_val = min(nums), max(nums)
        diff, res = max_val - min_val, 0
        for d in range(-diff, diff + 1):
            f = [0] * (max_val + 1)
            for x in nums:
                if min_val <= (prev := x + d) <= max_val:
                    f[x] = max(f[x], f[prev] + 1)
                    res = max(f[x], res)
                f[x] = max(f[x], 1)
        return res
