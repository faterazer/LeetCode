class Solution:
    def getSneakyNumbers(self, nums: list[int]) -> list[int]:
        n = len(nums)
        i = n - 2
        while i < n:
            if nums[nums[i]] == nums[i]:
                i += 1
            else:
                nums[nums[i]], nums[i] = nums[i], nums[nums[i]]
        return [nums[n - 2], nums[n - 1]]
