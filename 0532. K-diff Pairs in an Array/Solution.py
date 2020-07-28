from collections import Counter
from typing import List

class Solution:
    def findPairs(self, nums: List[int], k: int) -> int:
        if k < 0:
            return 0
        c = Counter(nums)
        if k == 0:
            return sum(c[n] > 1 for n in c)
        else:
            return sum(n + k in c for n in c)
