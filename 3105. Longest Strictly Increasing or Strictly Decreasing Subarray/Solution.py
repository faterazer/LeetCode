from typing import List


class Solution:
    def longestMonotonicSubarray(self, nums: List[int]) -> int:
        ans, i, n = 1, 0, len(nums)
        while i < n - 1:
            if nums[i] == nums[i + 1]:
                i += 1
                continue
            j = i + 1
            inc = nums[j] > nums[i]
            while j < n and nums[j] != nums[j - 1] and (nums[j] > nums[j - 1]) == inc:
                j += 1
            ans = max(ans, j - i)
            i = j - 1
        return ans
