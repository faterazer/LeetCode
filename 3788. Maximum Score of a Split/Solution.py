import sys


class Solution:
    def maximumScore(self, nums: list[int]) -> int:
        pre_sum, suf_min = sum(nums), sys.maxsize
        result = -sys.maxsize
        for i in range(len(nums) - 1, 0, -1):
            pre_sum -= nums[i]
            suf_min = min(suf_min, nums[i])
            result = max(result, pre_sum - suf_min)
        return result
