from typing import List


class Solution:
    def numberOfAlternatingGroups(self, colors: List[int]) -> int:
        n = len(colors)
        return sum(c != colors[(i - 1) % n] and c != colors[(i + 1) % n] for i, c in enumerate(colors))
