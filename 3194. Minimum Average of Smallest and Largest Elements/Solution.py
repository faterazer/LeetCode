from typing import List


class Solution:
    def minimumAverage(self, nums: List[int]) -> float:
        nums.sort()
        return min(nums[i] + nums[-1 - i] for i in range(len(nums) // 2)) / 2
