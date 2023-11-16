from typing import List


class Solution:
    def longestAlternatingSubarray(self, nums: List[int], threshold: int) -> int:
        n, res = len(nums), 0
        i = 0
        while i < n:
            if nums[i] % 2 == 1 or nums[i] > threshold:
                i += 1
                continue
            j = i + 1
            while j < n and nums[j] <= threshold and (nums[j] % 2) != (nums[j - 1] % 2):
                j += 1
            res = max(res, j - i)
            i = j
        return res
