from typing import List


class Solution:
    def getSumAbsoluteDifferences(self, nums: List[int]) -> List[int]:
        n, left, right = len(nums), 0, sum(nums)
        res = [0] * n
        for i, e in enumerate(nums):
            res[i] = right + e * (2 * i - n) - left
            left += e
            right -= e
        return res
