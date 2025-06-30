import heapq


class Solution:
    def maxSubsequence(self, nums: list[int], k: int) -> list[int]:
        ids = heapq.nlargest(k, range(len(nums)), key=nums.__getitem__)
        return [nums[i] for i in sorted(ids)]
