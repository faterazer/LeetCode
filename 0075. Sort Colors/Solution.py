class Solution:
    def sortColors(self, nums: list[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        i, k = 0, len(nums) - 1
        for j in range(k + 1):
            while i <= j <= k and nums[j] != 1:
                if nums[j] == 0:
                    nums[i], nums[j] = nums[j], nums[i]
                    i += 1
                else:
                    nums[j], nums[k] = nums[k], nums[j]
                    k -= 1
