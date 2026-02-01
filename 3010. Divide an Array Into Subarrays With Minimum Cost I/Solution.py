from heapq import nsmallest


class Solution:
    def minimumCost(self, nums: list[int]) -> int:
        return nums[0] + sum(nsmallest(2, nums[1:]))
