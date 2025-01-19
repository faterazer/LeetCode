from math import inf
from typing import List


class Solution:
    def minimumSubarrayLength(self, nums: List[int], k: int) -> int:
        ans = inf
        right_or = i = bottom = 0
        for j, x in enumerate(nums):
            right_or |= x
            while i <= j and (nums[i] | right_or) >= k:
                ans = min(ans, j - i + 1)
                i += 1
                if bottom < i:
                    for w in range(j - 1, i - 1, -1):
                        nums[w] |= nums[w + 1]
                    bottom = j
                    right_or = 0
        return -1 if ans is inf else ans
