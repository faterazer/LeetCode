from typing import List


class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        return sum(9 < n < 100 or 999 < n < 10000 or n > 99999 for n in nums)
