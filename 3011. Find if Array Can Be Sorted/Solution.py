from typing import List


class Solution:
    def canSortArray(self, nums: List[int]) -> bool:
        last_mx = 0
        mn = mx = nums[0]
        for i in range(1, len(nums)):
            if nums[i].bit_count() == nums[i - 1].bit_count():
                mn, mx = min(mn, nums[i]), max(mx, nums[i])
            else:
                if mn < last_mx:
                    return False
                last_mx = mx
                mn = mx = nums[i]
        return mn >= last_mx
