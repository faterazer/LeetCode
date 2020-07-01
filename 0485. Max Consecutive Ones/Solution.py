from typing import List


class Solution:
    def findMaxConsecutiveOnes_MK1(self, nums: List[int]) -> int:
        return max(map(len, ''.join(map(str, nums)).split('0')))

    def findMaxConsecutiveOnes_MK2(self, nums: List[int]) -> int:
        maximum = count = 0
        for n in nums:
            if n:
                count += 1
            else:
                maximum = max(maximum, count)
                count = 0
        return max(maximum, count)
