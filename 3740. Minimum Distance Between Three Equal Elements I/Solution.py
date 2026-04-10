class Solution:
    def minimumDistance(self, nums: list[int]) -> int:
        n = len(nums)
        last1 = [-n] * (n + 1)
        last2 = [-n] * (n + 1)
        result = n * 2
        for i, x in enumerate(nums):
            result = min(result, (i - last2[x]) * 2)
            last2[x], last1[x] = last1[x], i
        return -1 if result == n * 2 else result
