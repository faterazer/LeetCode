from typing import List


class Solution:
    def findColumnWidth(self, grid: List[List[int]]) -> List[int]:
        return [len(str(max(max(col), -10 * min(col)))) for col in zip(*grid)]
