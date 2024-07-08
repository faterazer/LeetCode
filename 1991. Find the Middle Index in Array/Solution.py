from typing import List


class Solution:
    def findMiddleIndex(self, nums: List[int]) -> int:
        left_sum, right_sum = 0, sum(nums)
        for i, e in enumerate(nums):
            right_sum -= e
            if left_sum == right_sum:
                return i
            left_sum += e
        return -1
