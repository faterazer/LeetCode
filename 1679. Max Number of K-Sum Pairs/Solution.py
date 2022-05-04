from collections import Counter
from typing import List


class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:
        c = Counter(nums)
        return sum(min(c[x], c[k - x]) for x in c.keys()) // 2
