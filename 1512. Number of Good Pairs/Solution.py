import collections
from typing import List


class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        return sum(v * (v - 1) // 2 for v in collections.Counter(nums).values())
