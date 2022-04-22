from typing import List


class Solution:
    def maxRotateFunction(self, nums: List[int]) -> int:
        f, n, accum = 0, len(nums), sum(nums)
        for i, e in enumerate(nums):
            f += i * e
        res = f
        for i in range(n - 1, 0, -1):
            f += accum - n * nums[i]
            res = max(res, f)
        return res
