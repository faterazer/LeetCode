class Solution:
    def minimumDifference(self, nums: list[int], k: int) -> int:
        nums.sort()
        return min(a - b for a, b in zip(nums[k-1:], nums))
