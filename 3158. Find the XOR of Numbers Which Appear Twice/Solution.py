from typing import List


class Solution:
    def duplicateNumbersXOR(self, nums: List[int]) -> int:
        ans = st = 0
        for x in nums:
            if st & (1 << x):
                ans ^= x
            st |= 1 << x
        return ans
