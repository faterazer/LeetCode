from typing import List


class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if len(nums) <= 2:
            return len(nums)
        ans = 2
        for i in range(2, len(nums)):
            if nums[i] != nums[ans - 2]:
                nums[ans] = nums[i]
                ans += 1
        return ans
