from itertools import accumulate
from typing import List


class Solution:
    # 时间复杂度：O(n)，空间复杂度：O(n)
    def maximumBeauty_MK1(self, nums: List[int], k: int) -> int:
        max_val = max(nums)
        diff = [0] * (max_val + 2)
        for x in nums:
            diff[max(0, x - k)] += 1
            diff[min(max_val, x + k) + 1] -= 1

        return max(accumulate(diff))

    # 时间复杂度：O(nlgn)，空间复杂度：O(1)
    def maximumBeauty_MK2(self, nums: List[int], k: int) -> int:
        nums.sort()
        res = left = 0
        for right, x in enumerate(nums):
            while x - nums[left] > k * 2:
                left += 1
            res = max(res, right - left + 1)
        return res
