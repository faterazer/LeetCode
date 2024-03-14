from functools import reduce
from typing import List


class Solution:
    def maxArrayValue(self, nums: List[int]) -> int:
        return reduce(lambda x, y: x + y if x >= y else y, reversed(nums))
