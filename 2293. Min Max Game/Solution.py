from typing import List


class Solution:
    def minMaxGame(self, nums: List[int]) -> int:
        n = len(nums)
        while n != 1:
            for i in range(n // 2):
                if i & 1:
                    nums[i] = max(nums[i << 1], nums[i << 1 | 1])
                else:
                    nums[i] = min(nums[i << 1], nums[i << 1 | 1])
            n >>= 1
        return nums[0]
