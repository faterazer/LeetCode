from typing import List


class Solution:
    def incremovableSubarrayCount(self, nums: List[int]) -> int:
        n = len(nums)
        i, j = 0, n - 1

        while j and nums[j] > nums[j - 1]:
            j -= 1
        if j == 0:
            return (1 + n) * n // 2

        res = n - j + 1
        while i == 0 or nums[i] > nums[i - 1]:
            while j < n and nums[i] >= nums[j]:
                j += 1
            res += n - j + 1
            i += 1
        return res
