from typing import List


class Solution:
    def check(self, nums: List[int]) -> bool:
        return sum(a > b for a, b in zip(nums, nums[1:] + nums[:1])) < 2
