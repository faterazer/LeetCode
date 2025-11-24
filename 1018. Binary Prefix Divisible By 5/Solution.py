class Solution:
    def prefixesDivBy5(self, nums: list[int]) -> list[bool]:
        result = [False] * len(nums)
        n = 0
        for i, bit in enumerate(nums):
            n = (n << 1 | bit) % 5
            result[i] = n == 0
        return result
