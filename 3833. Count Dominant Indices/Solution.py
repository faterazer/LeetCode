class Solution:
    def dominantIndices(self, nums: list[int]) -> int:
        n = len(nums)
        suf_sum = result = 0
        for i in range(n - 2, -1, -1):
            suf_sum += nums[i + 1]
            if nums[i] > suf_sum // (n - 1 - i):
                result += 1
        return result
