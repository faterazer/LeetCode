from typing import List


class Solution:
    def minimumDifference(self, nums: List[int], k: int) -> int:
        nums.sort()
        return min(a - b for a, b in zip(nums[k-1:], nums))
