from typing import List


class Solution:
    def resultsArray(self, nums: List[int], k: int) -> List[int]:
        ans = [-1] * (len(nums) - k + 1)
        windows_size = 0
        for i, x in enumerate(nums):
            if i == 0 or x == nums[i - 1] + 1:
                windows_size += 1
            else:
                windows_size = 1
            if windows_size >= k:
                ans[i - k + 1] = x
        return ans
