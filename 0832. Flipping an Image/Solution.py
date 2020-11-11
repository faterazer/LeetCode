from typing import List


class Solution:
    def flipAndInvertImage(self, A: List[List[int]]) -> List[List[int]]:
        return [[e ^ 1 for e in reversed(row)] for row in A]
        