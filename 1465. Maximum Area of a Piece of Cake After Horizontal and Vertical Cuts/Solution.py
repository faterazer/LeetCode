from itertools import chain
from typing import List


class Solution:
    def maxArea(self, h: int, w: int, horizontalCuts: List[int], verticalCuts: List[int]) -> int:
        def getMax(n: int, cuts: List[int]) -> int:
            cuts.sort()
            return max(chain([a - b for a, b in zip(cuts[1:], cuts)], [cuts[0], n - cuts[-1]]))

        P = 10 ** 9 + 7
        return getMax(h, horizontalCuts) * getMax(w, verticalCuts) % P
