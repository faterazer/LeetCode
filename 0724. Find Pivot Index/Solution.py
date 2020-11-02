from typing import List


class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        leftSum, rightSum = 0, sum(nums)
        for i, n in enumerate(nums):
            rightSum -= n
            if leftSum == rightSum:
                return i
            leftSum += n
        return -1
