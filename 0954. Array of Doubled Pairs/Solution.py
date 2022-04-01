from collections import Counter
from typing import List


class Solution:
    def canReorderDoubled(self, arr: List[int]) -> bool:
        c = Counter(arr)
        for x in sorted(c, key=abs):
            if c[x] > c[2 * x]:
                return False
            c[2 * x] -= c[x]
        return True
