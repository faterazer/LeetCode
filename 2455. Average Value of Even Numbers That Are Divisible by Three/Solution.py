from typing import List


class Solution:
    def averageValue(self, nums: List[int]) -> int:
        total = cnt = 0
        for x in nums:
            if x % 6 == 0:
                total += x
                cnt += 1
        return total // cnt if cnt else 0
