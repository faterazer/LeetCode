class Solution:
    def minimumDistance(self, nums: list[int]) -> int:
        n = len(nums)
        last2, last1 = [-n] * (n + 1), [-n] * (n + 1)
        result = 2 * n
        for i, x in enumerate(nums):
            result = min(result, (i - last2[x]) << 1)
            last2[x], last1[x] = last1[x], i
        return -1 if result == 2 * n else result
