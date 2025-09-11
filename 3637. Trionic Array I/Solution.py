class Solution:
    def isTrionic(self, nums: list[int]) -> bool:
        if nums[1] <= nums[0]:
            return False
        cnt = 0
        for i in range(2, len(nums)):
            if nums[i] == nums[i - 1]:
                return False
            if (nums[i] > nums[i - 1]) != (nums[i - 1] > nums[i - 2]):
                cnt += 1
            if cnt > 2:
                return False
        return cnt == 2
