from typing import List


class Solution:
    def validSquare(self, p1: List[int], p2: List[int], p3: List[int], p4: List[int]) -> bool:
        def dist(x: List[int], y: List[int]) -> int:
            return (y[1] - x[1]) ** 2 + (y[0] - x[0]) ** 2

        side_lens = sorted([dist(p1, p2), dist(p1, p3), dist(p1, p4), dist(p2, p3), dist(p2, p4), dist(p3, p4)])
        return side_lens[0] == side_lens[3] and side_lens[3] != side_lens[4] and side_lens[4] == side_lens[5]
