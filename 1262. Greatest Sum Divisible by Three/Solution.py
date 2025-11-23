from math import inf


class Solution:
    def maxSumDivThree(self, nums: list[int]) -> int:
        f = [0, -inf, -inf]
        for x in nums:
            f = [max(f[i], f[(i - x % 3) % 3] + x) for i in range(3)]
        return f[0]
