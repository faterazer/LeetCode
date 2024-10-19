from itertools import pairwise
from typing import List


class Solution:
    def minOperations(self, nums: List[int]) -> int:
        return (nums[0] ^ 1) + sum(x ^ y for x, y in pairwise(nums))
