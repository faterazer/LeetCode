class Solution:
    def minOperations(self, nums: list[int], k: int) -> int:
        mn = min(nums)
        if mn < k:
            return -1
        return len(set(nums)) - (mn == k)
