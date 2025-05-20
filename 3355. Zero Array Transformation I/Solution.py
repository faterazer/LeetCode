from itertools import accumulate


class Solution:
    def isZeroArray(self, nums: list[int], queries: list[list[int]]) -> bool:
        n = len(nums)
        diff = [0] * (n + 1)
        for l, r in queries:
            diff[l] += 1
            diff[r + 1] -= 1

        return all(a <= b for a, b in zip(nums, accumulate(diff)))
