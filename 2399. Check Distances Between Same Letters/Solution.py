from typing import List


class Solution:
    def checkDistances(self, s: str, distance: List[int]) -> bool:
        last = [0] * 26
        for i, c in enumerate(s):
            c = ord(c) - ord("a")
            if last[c] and i - last[c] != distance[c]:
                return False
            last[c] = i + 1
        return True
