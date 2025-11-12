from itertools import pairwise
from math import gcd, inf


class Solution:
    def minOperations(self, nums: list[int]) -> int | float:

        def helper(x: int, y: int) -> int | float:
            g = gcd(x, y)
            if g == 1:
                return 1
            if g == x or g == y:
                return inf
            return 1 + min(helper(x, gcd(x, y)), helper(y, gcd(x, y)))

        ans = inf
        for a, b in pairwise(nums):
            ans = min(ans, helper(a, b))
        return ans + len(nums) - 1 if ans != inf else -1
