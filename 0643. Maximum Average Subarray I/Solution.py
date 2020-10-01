from typing import List


class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        accum = maxAccum = sum(nums[:k])
        for i in range(k, len(nums)):
            accum += nums[i] - nums[i - k]
            maxAccum = max(maxAccum, accum)
        return maxAccum / k
