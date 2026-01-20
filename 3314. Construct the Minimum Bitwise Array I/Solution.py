class Solution:
    def minBitwiseArray(self, nums: list[int]) -> list[int]:
        for i, x in enumerate(nums):
            if x % 2 == 0:
                nums[i] = -1
            else:
                nums[i] ^= ((x + 1) & ~x) >> 1;
        return nums
