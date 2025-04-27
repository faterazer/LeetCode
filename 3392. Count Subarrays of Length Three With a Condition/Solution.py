class Solution:
    def countSubarrays(self, nums: list[int]) -> int:
        return sum(2 * (nums[i - 2] + nums[i]) == nums[i - 1] for i in range(2, len(nums)))
