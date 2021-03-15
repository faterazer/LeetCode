import itertools
from typing import List


class Solution:
    def minStartValue(self, nums: List[int]) -> int:
        return 1 - min(min(itertools.accumulate(nums)), 0)
