from math import inf


class Solution:
    def maxSubarraySum(self, nums: list[int], k: int) -> int | float:
        min_f = [inf] * k
        min_f[0] = 0
        pre_sum, result = 0, -inf
        for j, x in enumerate(nums):
            pre_sum += x
            i = (j + 1) % k
            result = max(result, pre_sum - min_f[i])
            min_f[i] = min(min_f[i], pre_sum)
        return result
