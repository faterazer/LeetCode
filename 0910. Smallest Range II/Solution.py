from typing import List


class Solution:
    def smallestRangeII(self, nums: List[int], k: int) -> int:
        nums.sort()
        ans = nums[-1] - nums[0]
        for i in range(1, len(nums)):
            mx = max(nums[i - 1] + k, nums[-1] - k)
            mn = min(nums[0] + k, nums[i] - k)
            ans = min(ans, mx - mn)
        return ans
