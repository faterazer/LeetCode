from typing import List


class Solution:
    def minPatches(self, nums: List[int], n: int) -> int:
        res = max_right = i = 0
        while max_right < n:
            if i < len(nums) and nums[i] <= max_right + 1:
                max_right += nums[i]
                i += 1
            else:
                res += 1
                max_right = 2 * max_right + 1
        return res
