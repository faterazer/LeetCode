from typing import List


class Solution:
    def findTheArrayConcVal(self, nums: List[int]) -> int:
        res, n = 0, len(nums)
        i, j = 0, n - 1
        while i <= j:
            if i == j:
                res += nums[i]
            else:
                res += int(str(nums[i]) + str(nums[j]))
            i += 1
            j -= 1
        return res
