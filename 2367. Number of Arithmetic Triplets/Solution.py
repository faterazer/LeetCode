from typing import List


class Solution:
    def arithmeticTriplets(self, nums: List[int], diff: int) -> int:
        res = i = j = 0
        for e in nums:
            while nums[j] + diff < e:
                j += 1
            if nums[j] + diff > e:
                continue
            while nums[i] + 2 * diff < e:
                i += 1
            if nums[i] + 2 * diff == e:
                res += 1
        return res
