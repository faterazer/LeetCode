from typing import List


class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if matrix:
            return [*matrix.pop(0)] + self.spiralOrder([*zip(*matrix)][::-1])
        else:
            return []
