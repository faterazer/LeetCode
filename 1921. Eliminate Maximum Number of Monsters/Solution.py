from typing import List


class Solution:
    def eliminateMaximum(self, dist: List[int], speed: List[int]) -> int:
        arrival = sorted([(d - 1) // s + 1 for d, s in zip(dist, speed)])
        for i, e in enumerate(arrival):
            if e <= i:
                return i
        return len(dist)
