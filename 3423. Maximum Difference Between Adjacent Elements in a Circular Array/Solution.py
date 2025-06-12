from itertools import pairwise


class Solution:
    def maxAdjacentDistance(self, nums: list[int]) -> int:
        ans = max(abs(x - y) for x, y in pairwise(nums))
        return max(ans, abs(nums[0] - nums[-1]))
