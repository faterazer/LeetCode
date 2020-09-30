from typing import List


class Solution:
    def checkPossibility(self, nums: List[int]) -> bool:
        cnt = 0
        for i in range(len(nums) - 1):
            if nums[i] > nums[i + 1]:
                cnt += 1
                if cnt > 1:
                    return False
                if i != 0 and i + 1 != len(nums) - 1 and nums[i] > nums[i + 2] and nums[i + 1] < nums[i - 1]:
                    return False
        return True
