class Solution:
    def constructTransformedArray(self, nums: list[int]) -> list[int]:
        n = len(nums)
        return [nums[(i + x) % n] for i, x in enumerate(nums)]
