from itertools import pairwise
from typing import List


class Solution:
    def findValueOfPartition(self, nums: List[int]) -> int:
        return min(b - a for a, b in pairwise(sorted(nums)))
