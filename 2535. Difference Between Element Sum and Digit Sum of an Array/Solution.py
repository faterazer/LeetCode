from itertools import chain
from typing import List


class Solution:
    def differenceOfSum(self, nums: List[int]) -> int:
        return sum(nums) - sum(map(int, chain.from_iterable(map(str, nums))))
