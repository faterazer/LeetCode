from typing import List


class Solution:
    def mostVisited(self, n: int, rounds: List[int]) -> List[int]:
        beg, end = rounds[0], rounds[-1]
        return range(beg, end + 1) or range(1, beg + 1) + range(end, n + 1)
