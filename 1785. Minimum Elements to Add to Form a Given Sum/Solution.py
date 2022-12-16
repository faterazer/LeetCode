import math
from typing import List


class Solution:
    def minElements(self, nums: List[int], limit: int, goal: int) -> int:
        need = abs(sum(nums) - goal)
        return math.ceil(need / limit)
