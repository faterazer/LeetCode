from typing import List


class Solution:
    def countGoodRectangles(self, rectangles: List[List[int]]) -> int:
        mx, cnt = 0, 0
        for l, w in rectangles:
            side = min(l, w)
            if mx < side:
                mx = side
                cnt = 1
            elif mx == side:
                cnt += 1
        return cnt
