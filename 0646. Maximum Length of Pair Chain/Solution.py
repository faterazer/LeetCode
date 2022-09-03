from cmath import inf
from typing import List


class Solution:
    def findLongestChain(self, pairs: List[List[int]]) -> int:
        last, res = -inf, 0
        for x, y in sorted(pairs, key=lambda x: x[1]):
            if x > last:
                last = y
                res += 1
        return res
