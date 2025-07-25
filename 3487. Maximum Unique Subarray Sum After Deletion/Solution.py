class Solution:
    def maxSum(self, nums: list[int]) -> int:
        pos_st = set(x for x in nums if x >= 0)
        return sum(pos_st) if pos_st else max(nums)
