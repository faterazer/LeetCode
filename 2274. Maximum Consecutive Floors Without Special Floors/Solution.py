from itertools import pairwise
from typing import List


class Solution:
    def maxConsecutive(self, bottom: int, top: int, special: List[int]) -> int:
        special.sort()
        ans = max(special[0] - bottom, top - special[-1])
        for a, b in pairwise(special):
            ans = max(ans, b - a - 1)
        return ans
