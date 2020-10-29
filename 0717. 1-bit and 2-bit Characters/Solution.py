from typing import List


class Solution:
    def isOneBitCharacter(self, bits: List[int]) -> bool:
        ones = 0
        i = len(bits) - 2
        while i >= 0 and bits[i]:
            ones += 1
            i -= 1
        return ones % 2 == 0
