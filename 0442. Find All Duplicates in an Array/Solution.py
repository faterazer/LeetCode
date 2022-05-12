from typing import List


class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        res = []
        for e in nums:
            idx = abs(e) - 1
            if nums[idx] < 0:
                res.append(idx + 1)
            else:
                nums[idx] *= -1
        return res
