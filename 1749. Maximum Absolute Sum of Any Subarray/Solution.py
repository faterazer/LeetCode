class Solution:
    def maxAbsoluteSum(self, nums: list[int]) -> int:
        min_sum = max_sum = ans = 0
        for num in nums:
            min_sum = min(num, min_sum + num)
            max_sum = max(num, max_sum + num)
            ans = max(ans, max_sum, -min_sum)
        return ans
