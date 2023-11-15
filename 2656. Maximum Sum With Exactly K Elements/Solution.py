from typing import List


class Solution:
    def maximizeSum(self, nums: List[int], k: int) -> int:
        max_val = max(nums)
        return k * (2 * max_val + k - 1) // 2
